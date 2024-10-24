#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        int accum = 1, pre = ratings[0], result = 0;
        for (int i = 0; i < ratings.size(); i++) {
            if (ratings[i] > pre) {
                result += (accum + 1);
            } else {
                accum = 1;
            }
            pre = ratings[i];
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> ratings = {1,0,2};

    int result = s.candy(ratings);

    cout << result << endl;

    return 0;
}