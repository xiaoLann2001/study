#include <iostream>
#include <vector>

using namespace std;

// 打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 堆的性质：

// 调整堆，使其保持最大堆性质
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          // 假设当前节点最大
    int left = 2 * i + 1;     // 左子节点索引
    int right = 2 * i + 2;    // 右子节点索引

    // 如果左子节点更大，则更新 largest
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点更大，则更新 largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果 largest 发生了变化，则交换并继续调整
    if (largest != i) {
        swap(arr[i], arr[largest]);  // 交换当前节点和最大子节点
        heapify(arr, n, largest);    // 递归调整子堆
    }
}

// 构建最大堆
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    // 从最后一个非叶子节点开始调整
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// 堆排序
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 1. 构建最大堆
    buildMaxHeap(arr);

    // 2. 交换堆顶和末尾元素，并重新调整堆
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);  // 将最大元素放到数组末尾
        heapify(arr, i, 0);    // 调整剩余元素，保持最大堆
    }
}

int main() {
    vector<int> arr = {8, 4, 2, 9, 5, 7, 1, 3, 6};

    cout << "排序前: ";
    printArray(arr);

    heapSort(arr);

    cout << "排序后: ";
    printArray(arr);

    return 0;
}
