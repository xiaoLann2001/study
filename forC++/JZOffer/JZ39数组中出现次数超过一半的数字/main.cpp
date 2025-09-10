#include <bits/stdc++.h>

using namespace std;

// Partition法，寻找第 k 大的数（快速选择），会修改数组
class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        int mid = numbers.size() >> 1;
        int index = Partition(numbers, left, right);

        while (index != mid) {
            if (index > mid) {
                right = index - 1;
                index = Partition(numbers, left, right);
            } else {
                left = index + 1;
                index = Partition(numbers, left, right);
            }
        }

        return numbers[mid];
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

// 摩尔投票法
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        int candidate = 0;
        int count = 0;
        
        for (int i = 0; i < numbers.size(); i++) {
            if (count == 0) {
                candidate = numbers[i];
                count++;
            } else {
                if (numbers[i] == candidate)
                    count++;
                else
                    count--;
            }
        }

        return candidate;
    }
};

int main() {
    Solution s;

    vector<int> nums = {3,3,3,3,3,2,2,2,2};

    int ret = s.MoreThanHalfNum_Solution(nums);

    cout << ret << endl;

    return 0;
}