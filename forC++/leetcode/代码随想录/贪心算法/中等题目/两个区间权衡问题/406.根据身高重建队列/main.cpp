#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> first, vector<int> second) {
        if (first[0] > second[0]) return true;
        else if (first[0] == second[0] && first[1] < second[1]) return true;
        return false;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.size() == 1) return people;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++) {
            if (people[i][1] != i) {
                int start = people[i][1];
                vector<int> temp = people[i];
                for (int j = i; j > start; j--) {
                    people[j] = people[j - 1];
                }
                people[start] = temp;
            }
        }
        return people;
    }
};

int main() {
    Solution s;

    vector<vector<int>> people = {{9,0},
                                  {7,0},
                                  {1,9},
                                  {3,0},
                                  {2,7},
                                  {5,3},
                                  {6,0},
                                  {3,4},
                                  {6,2},
                                  {5,2}};

    vector<vector<int>> result = s.reconstructQueue(people);

    cout << "[ ";
    for (vector<int> p : result) {
        cout << "[ ";
        for (int i : p) {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "] " << endl;

    return 0;
}