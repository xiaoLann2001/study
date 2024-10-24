#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
 
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0;  // 记录5美元的个数
        int count_10 = 0;
        int count_20 = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) count_5++;
            else if (bills[i] == 10) {
                count_10++;
                if (count_5 >= 1) count_5--;
                else return false;
            }
            else if (bills[i] == 20) {
                count_20++;
                if (count_10 >= 1 && count_5 >= 1) {
                    count_10--;
                    count_5--;
                } else if (count_5 >= 3) {
                    count_5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    vector<int> bills = {5,5,5,5,20,20,5,5,20,5};

    bool result = s.lemonadeChange(bills);

    if (result) 
        cout << "true" << endl;
    else 
        cout << "false" << endl;
    return 0;
}