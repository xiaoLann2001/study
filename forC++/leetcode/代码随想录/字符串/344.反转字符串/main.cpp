#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left, right;
        left = 0;
        right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

int main() {
    Solution s;

    vector<char> str = {'h','e','l','l','o'};

    s.reverseString(str);

    for (char c : str) {
        cout << c;
    }
    cout << endl;

    return 0;
}