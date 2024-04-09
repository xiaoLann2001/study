// compile cmd:
// g++ -o onnxtest onnxtest.cpp $(pkg-config --cflags --libs opencv4)

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <time.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace dnn;
using namespace std;

atomic<bool> isProcessing(true);

struct Net_config
{
	float confThreshold; // Confidence threshold
	float nmsThreshold;	 // Non-maximum suppression threshold
	float objThreshold;	 // Object Confidence threshold
	string modelpath;
};

const float anchors_640[3][6] = {{10.0, 13.0, 16.0, 30.0, 33.0, 23.0},
								 {30.0, 61.0, 62.0, 45.0, 59.0, 119.0},
								 {116.0, 90.0, 156.0, 198.0, 373.0, 326.0}};

class YOLO
{
public:
	YOLO(Net_config config);
	void detect(Mat &frame);

private:
	float *anchors;
	int num_stride;
	int inpWidth;
	int inpHeight;
	vector<string> class_names;
	int num_class;

	float confThreshold;
	float nmsThreshold;
	float objThreshold;
	const bool keep_ratio = true;
	Net net;
	void drawPred(float conf, int left, int top, int right, int bottom, Mat &frame, int classid);
	Mat resize_image(Mat srcimg, int *newh, int *neww, int *top, int *left);
};

YOLO::YOLO(Net_config config)
{
	this->confThreshold = config.confThreshold;
	this->nmsThreshold = config.nmsThreshold;
	this->objThreshold = config.objThreshold;

	this->net = readNet(config.modelpath);
	ifstream ifs("class.names");
	string line;
	while (getline(ifs, line))
		this->class_names.push_back(line);
	this->num_class = class_names.size();

	anchors = (float *)anchors_640;
	this->num_stride = 3;
	this->inpHeight = 640;
	this->inpWidth = 640;
}

Mat YOLO::resize_image(Mat srcimg, int *newh, int *neww, int *top, int *left)
{
	int srch = srcimg.rows, srcw = srcimg.cols;
	*newh = this->inpHeight;
	*neww = this->inpWidth;
	Mat dstimg;
	if (this->keep_ratio && srch != srcw)
	{
		float hw_scale = (float)srch / srcw;
		if (hw_scale > 1)
		{
			*newh = this->inpHeight;
			*neww = int(this->inpWidth / hw_scale);
			resize(srcimg, dstimg, Size(*neww, *newh), INTER_AREA);
			*left = int((this->inpWidth - *neww) * 0.5);
			copyMakeBorder(dstimg, dstimg, 0, 0, *left, this->inpWidth - *neww - *left, BORDER_CONSTANT, 114);
		}
		else
		{
			*newh = (int)this->inpHeight * hw_scale;
			*neww = this->inpWidth;
			resize(srcimg, dstimg, Size(*neww, *newh), INTER_AREA);
			*top = (int)(this->inpHeight - *newh) * 0.5;
			copyMakeBorder(dstimg, dstimg, *top, this->inpHeight - *newh - *top, 0, 0, BORDER_CONSTANT, 114);
		}
	}
	else
	{
		resize(srcimg, dstimg, Size(*neww, *newh), INTER_AREA);
	}
	return dstimg;
}

void YOLO::drawPred(float conf, int left, int top, int right, int bottom, Mat &frame, int classid) // Draw the predicted bounding box
{
	// Draw a rectangle displaying the bounding box
	rectangle(frame, Point(left, top), Point(right, bottom), Scalar(0, 0, 255), 2);

	// Get the label for the class name and its confidence
	string label = format("%.2f", conf);
	label = this->class_names[classid] + ":" + label;

	// Display the label at the top of the bounding box
	int baseLine;
	Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
	top = max(top, labelSize.height);
	// rectangle(frame, Point(left, top - int(1.5 * labelSize.height)), Point(left + int(1.5 * labelSize.width), top + baseLine), Scalar(0, 255, 0), FILLED);
	putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 255, 0), 1);
}

void YOLO::detect(Mat &frame)
{
	int newh = 0, neww = 0, padh = 0, padw = 0;
	Mat dstimg = this->resize_image(frame, &newh, &neww, &padh, &padw);
	Mat blob = blobFromImage(dstimg, 1 / 255.0, Size(this->inpWidth, this->inpHeight), Scalar(0, 0, 0), true, false);
	this->net.setInput(blob);
	vector<Mat> outs;
	this->net.forward(outs, this->net.getUnconnectedOutLayersNames());

	int num_proposal = outs[0].size[1];
	int nout = outs[0].size[2];
	if (outs[0].dims > 2)
	{
		outs[0] = outs[0].reshape(0, num_proposal);
	}
	// generate proposals
	vector<float> confidences;
	vector<Rect> boxes;
	vector<int> classIds;
	float ratioh = (float)frame.rows / newh, ratiow = (float)frame.cols / neww;
	int n = 0, q = 0, i = 0, j = 0, row_ind = 0; /// xmin,ymin,xamx,ymax,box_score,class_score
	float *pdata = (float *)outs[0].data;

	for (n = 0; n < this->num_stride; n++) /// 特征图尺度
	{
		const float stride = pow(2, n + 3);
		int num_grid_x = (int)ceil((this->inpWidth / stride));
		int num_grid_y = (int)ceil((this->inpHeight / stride));
		for (q = 0; q < 3; q++) /// anchor
		{
			const float anchor_w = this->anchors[n * 6 + q * 2];
			const float anchor_h = this->anchors[n * 6 + q * 2 + 1];
			for (i = 0; i < num_grid_y; i++)
			{
				for (j = 0; j < num_grid_x; j++)
				{
					float box_score = pdata[4];
					if (box_score > this->objThreshold)
					{
						Mat scores = outs[0].row(row_ind).colRange(5, nout);
						Point classIdPoint;
						double max_class_socre;
						// Get the value and location of the maximum score
						minMaxLoc(scores, 0, &max_class_socre, 0, &classIdPoint);
						max_class_socre *= box_score;
						if (max_class_socre > this->confThreshold)
						{
							const int class_idx = classIdPoint.x;
							// float cx = (pdata[0] * 2.f - 0.5f + j) * stride;  ///cx
							// float cy = (pdata[1] * 2.f - 0.5f + i) * stride;   ///cy
							// float w = powf(pdata[2] * 2.f, 2.f) * anchor_w;   ///w
							// float h = powf(pdata[3] * 2.f, 2.f) * anchor_h;  ///h

							float cx = pdata[0]; /// cx
							float cy = pdata[1]; /// cy
							float w = pdata[2];	 /// w
							float h = pdata[3];	 /// h

							int left = int((cx - padw - 0.5 * w) * ratiow);
							int top = int((cy - padh - 0.5 * h) * ratioh);

							confidences.push_back((float)max_class_socre);
							boxes.push_back(Rect(left, top, (int)(w * ratiow), (int)(h * ratioh)));
							classIds.push_back(class_idx);
						}
					}
					row_ind++;
					pdata += nout;
				}
			}
		}
	}

	// Perform non maximum suppression to eliminate redundant overlapping boxes with
	// lower confidences
	vector<int> indices;
	dnn::NMSBoxes(boxes, confidences, this->confThreshold, this->nmsThreshold, indices);
	for (size_t i = 0; i < indices.size(); ++i)
	{
		int idx = indices[i];
		Rect box = boxes[idx];
		this->drawPred(confidences[idx], box.x, box.y,
					   box.x + box.width, box.y + box.height, frame, classIds[idx]);
	}
}

// 定义线程安全队列
template <typename T>
class SafeQueue
{
public:
	void push(const T &item)
	{
		lock_guard<mutex> lock(m_mutex);
		m_queue.push(item);
		m_condition.notify_one();
	}

	T pop()
	{
		unique_lock<mutex> lock(m_mutex);
		m_condition.wait(lock, [this]
						 { return !m_queue.empty(); });
		T item = m_queue.front();
		m_queue.pop();
		return item;
	}

	bool try_pop(T &item)
	{
		lock_guard<mutex> lock(m_mutex);
		if (m_queue.empty())
			return false;
		item = m_queue.front();
		m_queue.pop();
		return true;
	}

	bool empty() const
	{
		lock_guard<mutex> lock(m_mutex);
		return m_queue.empty();
	}

private:
	queue<T> m_queue;
	mutable mutex m_mutex;
	condition_variable m_condition;
};

// 定义模型推理线程函数
void inferenceThread(YOLO &yolo_model, SafeQueue<Mat> &inputQueue, SafeQueue<Mat> &outputQueue, mutex &outputMutex)
{
	while (isProcessing)
	{
		Mat frame;
		if (inputQueue.try_pop(frame))
		{
			// 进行模型推理
			yolo_model.detect(frame);

			// 将处理后的帧放入输出队列
			lock_guard<mutex> lock(outputMutex);
			outputQueue.push(frame);
		}
		else
		{
			// 如果队列为空，则继续执行
			this_thread::sleep_for(chrono::milliseconds(10)); // 避免空循环占用过多 CPU 时间
		}
	}
}

// 定义保存视频的函数
void saveVideoThread(VideoWriter &writer, SafeQueue<Mat> &outputQueue, mutex &outputMutex)
{
	while (isProcessing)
	{
		Mat frame;
		// 尝试从输出队列中获取处理后的帧
		if (outputQueue.try_pop(frame))
		{
			// 写入帧到视频文件
			writer.write(frame);
		}
		else
		{
			// 如果队列为空，则继续执行
			this_thread::sleep_for(chrono::milliseconds(10)); // 避免空循环占用过多 CPU 时间
		}
	}
}

int main()
{
	Net_config yolo_nets = {0.3, 0.5, 0.3, "best.onnx"};
	YOLO yolo_model(yolo_nets);

	string videoPath = "/home/book/Videos/helmet.mp4";
	VideoCapture capture(videoPath);
	if (!capture.isOpened())
	{
		cerr << "Failed to open the video file." << endl;
		return -1;
	}

	int frameCount = capture.get(CAP_PROP_FRAME_COUNT);
	int fps = capture.get(CAP_PROP_FPS);
	int frameWidth = capture.get(CAP_PROP_FRAME_WIDTH);
	int frameHeight = capture.get(CAP_PROP_FRAME_HEIGHT);

	cout << "frameCount: " << frameCount << endl
		 << "fps: " << fps << endl
		 << "frameWidth: " << frameWidth << endl
		 << "frameHeight: " << frameHeight << endl;

	VideoWriter writer;
	string outputVideoPath = "/home/book/Videos/result.mp4";
	int fourcc = VideoWriter::fourcc('m', 'p', '4', 'v');
	writer.open(outputVideoPath, fourcc, fps, Size(frameWidth, frameHeight));
	if (!writer.isOpened())
	{
		cerr << "Failed to create the output video file." << endl;
		return -1;
	}

	SafeQueue<Mat> inputQueue;	// 输入帧队列
	SafeQueue<Mat> outputQueue; // 输出帧队列
	mutex outputMutex;			// 输出队列的互斥锁

	// 创建模型推理线程
	thread inferenceThreadObj(inferenceThread, ref(yolo_model), ref(inputQueue), ref(outputQueue), ref(outputMutex));

	// 创建保存视频线程
	thread saveVideoThreadObj(saveVideoThread, ref(writer), ref(outputQueue), ref(outputMutex));

	Mat frame;
	isProcessing = true;
	for (int i = 0; i < frameCount; i++)
	{
		capture >> frame;

		// // 如果视频流结束，则退出循环
		// if (frame.empty())
		// {
		// 	while (true)
		// 	{
		// 		if (inputQueue.empty() && outputQueue.empty())
		// 			break;
		// 	}	
		// }

		// 主线程将视频帧压入队列
		inputQueue.push(frame);
	}

	isProcessing = false;

	// 等待保存视频线程结束
	saveVideoThreadObj.join();

	// 等待模型推理线程结束
	inferenceThreadObj.join();

	capture.release();
	writer.release();

	destroyAllWindows();

	return 0;
}
