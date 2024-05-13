#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 双循环暴力解法
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int size = nums.size();
//         for (int i = 0; i < size; ) {
//             if (nums[i] == val){
//                 for (int j = i; j < size - 1; j++){
//                     nums[j] = nums[j + 1];
//                 }
//                 size--;
//             }
//             else
//                 i++;
//         }

//         return size;
//     }
// };

// 单循环，逆向思维（找符合删除条件的，需要覆盖，找不符合删除条件的，只需要赋值给前面或当前的索引）
// 双指针法，快慢指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int index = 0;              // 记录应该保留（nums[i] != val）数据的新的索引
        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                ++index;
            }
        }
        return index;
    }
};

int main(){
    Solution s;

    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    int ret = s.removeElement(nums, val);
    cout << "ret = " << ret << endl;

    for_each(nums.begin(), nums.end(), [](int v) {
        cout << v << " ";
    });
    cout << endl;

    return 0;
}