// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

// 你可以按任意顺序返回答案。

#include <iostream>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 求两数之和等于目标值的下标
        // -->求目标值减去其中一个值的差在数组中的下标
        // 若某个数作减数没有找到另一个满足要求的数,
        // 那么这个数一定不属于最终结果,将其移出备选数
        // 因为要记录下标,所以采用key:value的map来处理
        
        vector<int> result;

        // 用来记录访问过的元素及其下标
        unordered_map<int, int> map;

        // 遍历数组,查看map中是否有key = (target-数组元素)
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator it;
            it = map.find(target - nums[i]);
            if (map.end() != it) {
                result.push_back(i);
                result.push_back((*it).second);
                return result;
            }
            map[nums[i]] = i;
        }

        result.push_back(0);
        result.push_back(0);
        return result;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {2, 7, 11, 15};
    vector<int> result;
    int target = 9;

    result = s.twoSum(nums, 9);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}