#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        // 初始化糖果数组，每人最少一个
        vector<int> candy(ratings.size(), 1);
        // 从左向右遍历，保证评分高的右孩子糖果比评分低的左孩子多
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
        }
        // 从右向左遍历，保证评分高的左孩子糖果比评分低的右孩子多
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) candy[i] = max(candy[i], candy[i + 1] + 1);
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};

int main() {
    Solution s;

    vector<int> ratings = {1,2,2};

    int result = s.candy(ratings);

    cout << result << endl;

    return 0;
}