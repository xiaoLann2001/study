// 给定两个数组 nums1 和 nums2 ，返回它们的交集。
// 输出结果中的每个元素一定是 唯一 的。
// 我们可以 不考虑输出结果的顺序 。

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1,
                             vector<int> &nums2)
    {
        // 将数组1填入集合
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> result;
        // 遍历数组2每一个元素,看是否在集合中能找到
        for (int i = 0; i < nums2.size(); i++)
        {
            // 若能找到,将数组2元素填入结果
            if (s.find(nums2[i]) != s.end())
            {
                result.insert(nums2[i]);
            }
        }
        // 结果用集合存,保证每个数是唯一的,最后转为数组
        return vector<int>(result.begin(), result.end());
    }
};

// 官方题解
class Solution1
{
public:
    vector<int> intersection(vector<int> &nums1,
                             vector<int> &nums2)
    {
        // 将数组1,数组2加入集合
        unordered_set<int> set1, set2;
        for (auto &num : nums1)
        {
            set1.insert(num);
        }
        for (auto &num : nums2)
        {
            set2.insert(num);
        }
        // 调用获取交集的函数,假定集合1小于集合2
        return getIntersection(set1, set2);
    }

    vector<int> getIntersection(unordered_set<int> &set1,
                                unordered_set<int> &set2)
    {
        if (set1.size() > set2.size())
        {
            return getIntersection(set2, set1);
        }
        // 遍历集合1的元素,若在集合2中频数不为0,则填入结果
        vector<int> intersection;
        for (auto &num : set1)
        {
            if (set2.count(num))
            {
                intersection.push_back(num);
            }
        }
        return intersection;
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {1, 2, 2, 1};
    vector<int> n2 = {2, 2};
    vector<int> result;

    result = s.intersection(n1, n2);

    for (int num : result)
    {
        cout << num << endl;
    }

    return 0;
}