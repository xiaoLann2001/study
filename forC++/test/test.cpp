#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; ) {
            if (nums[i] == val){
                for (int j = i; j < size - 1; j++){
                    nums[j] = nums[j + 1];
                }
                size--;
            }
            else
                i++;
        }

        return size;
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