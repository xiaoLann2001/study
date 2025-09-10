#include <bits/stdc++.h>

using namespace std;

// Partition法，寻找第 k 大的数（快速选择），会修改数组
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param input int整型vector 
     * @param k int整型 
     * @return int整型vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        int left = 0, right = input.size() - 1;
        int pivotIndex = Partition(input, left, right);
        while (pivotIndex != k) {
            if (pivotIndex > k) {
                right = pivotIndex - 1;
                pivotIndex = Partition(input, left, right);
            } else {
                left = pivotIndex + 1;
                pivotIndex = Partition(input, left, right);
            }
        }
        return vector<int>(input.begin(), input.begin() + k);
    }

    int Partition(vector<int>& numbers, int left, int right) {
        if (left >= right) return left;

        int pivot = rand() % (right - left + 1) + left;    // 选择枢轴元素
        swap(numbers[pivot], numbers[right]);   // 交换到最后，以便从头开始填充小于枢轴的元素（因为要和枢轴比较，所以枢轴的位置最好固定，且不会被覆盖）

        int j = left;  // 准备填充的起始位置
        for (int i = left; i < right; i++) {
            if (numbers[i] <= numbers[right]) {  // 若小于枢轴元素，依次从数组前方填充（交换）
                swap(numbers[i], numbers[j]);
                j++;
            }
        }

        swap(numbers[j], numbers[right]);   // 将数组末尾的枢轴元素交换到小于它的所有元素的下一个位置
        return j;   // 返回枢轴元素位置
    }
};

int main() {
    Solution s;

    vector<int> nums = {4,5,1,6,2,7,3,8};
    int k = 4;

    vector<int> ret = s.GetLeastNumbers_Solution(nums, k);

    for (auto n : ret)
        cout << n << " ";
    cout << endl;

    return 0;
}