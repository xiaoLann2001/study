#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                result += (prices[i] - prices[i - 1]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {7,1,5,3,6,4};

    int result = s.maxProfit(nums);

    cout << result << endl;

    return 0;
}