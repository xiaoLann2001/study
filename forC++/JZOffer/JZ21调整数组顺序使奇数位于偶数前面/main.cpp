#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// 时间复杂度O(n)，空间复杂度O(n)
class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // 要求不改变奇偶数原来的相对位置
        // 分离奇偶数
        int i = 0, j = 0;
        vector<int> odd, even;
        odd.reserve(array.size());
        even.reserve(array.size());
        for (i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 1)
                odd.push_back(array[i]);
            if (array[i] % 2 == 0)
                even.push_back(array[i]);
        }
        // 先奇数后偶数放回原数组
        for (i = 0; i < odd.size(); i++) {
            array[j++] = odd[i];
        }
        for (i = 0; i < even.size(); i++) {
            array[j++] = even[i];
        }
        return array;
    }
};

// 时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // 要求不改变奇偶数原来的相对位置
        int k = 0;  // 记录最靠前的偶数位置
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 1) {    // 若遇到奇数，将其插入到最前面的偶数前面
                int j = i - 1;
                int temp = array[i];
                while (j >= k) {
                    array[j + 1] = array[j];    // 后移
                    j--;
                }
                array[k] = temp;
                k++;
            }
        }
        return array;
    }
};

int main() {
    Solution s;

    vector<int> array = {2,4,6,5,7};

    vector<int> ret = s.reOrderArray(array);

    for (const auto& n : ret)
        cout << n << ' ';
    cout << endl;

    return 0;
}