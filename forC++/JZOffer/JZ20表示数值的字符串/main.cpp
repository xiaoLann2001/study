#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 
//      * @param str string字符串 
//      * @return bool布尔型
//      */
//     bool isNumeric(string str) {
//         // 如果一个字符串能表示数值，那么他一定由四大部分组成 A [. + B] [e/E + C], A为整数部分，后两个部分为小数部分和指数部分，由 . 和 e/E 领起
//         // 状态转移：
//         bool flagA = false, flagB = false, flagC = false;  // 表示整数小数指数部分是否不为空
//         int index = 0, ret = 0;  // 遍历每一个字符
//         // 跳过空格
//         checkSpace(str, index);

//         // 进入整数部分
//         if (str[index] == '-' || str[index] == '+') {
//             index++;
//         }
//         if (checkEnd(str, index))
//             return false;
//         if (checkNums(str, index) == 0)
//             flagA =  false;
//         else
//             flagA = true;
//         if (checkEnd(str, index))
//             return flagA;
        
//         // 进入小数部分
//         if (str[index] == '.') {
//             index++;
//             if (checkEnd(str, index)) { // 判断索引是否越界
//                 flagB = false;
//                 return flagA || flagB;
//             }   
//             if (checkNums(str, index) == 0)
//                 flagB =  false;
//             else
//                 flagB = true;
//             if (checkEnd(str, index))
//                 return flagA || flagB;
//         }

//         // 进入指数部分
//         if (str[index] == 'e' || str[index] == 'E') {
//             index++;
//             if (checkEnd(str, index))   // 判断索引是否越界
//                 return false;
//             if (str[index] == '-' || str[index] == '+') {
//                 index++;
//             }
//             if (checkEnd(str, index))   // 判断索引是否越界
//                 return false;
//             if (checkNums(str, index) == 0)
//                 flagC =  false;
//             else
//                 flagC = true;
//             if (checkEnd(str, index))
//                 return (flagA || flagB) && flagC;
//         }

//         // 跳过空格
//         checkSpace(str, index);
//         if (checkEnd(str, index))   // 遍历完字符串
//             return true;
//         return false;   // 字符串后面不全是空格
//     }

//     // 返回连续数字长度，并移动传入的index指针
//     int checkNums(string str, int& index) {
//         if (index >= str.size())    // 若越界返回0
//             return 0;
//         int len = 0;              // 开始遍历数字
//         while (index < str.size() && str[index] >= '0' && str[index] <= '9') {
//             index++;
//             len++;
//         }
//         return len;   // 返回连续数字长度
//     }

//     bool checkEnd(string str, int index) {
//         return index >= str.size(); // 判断是否超出数组范围
//     }

//     // 跳过空格
//     void checkSpace(string str, int &index) {
//         if (index >= str.size())    // 若越界返回0
//             return;
//         while (index < str.size() && str[index] == ' ') {
//             index++;
//         }
//     }
// };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool isNumeric(string str) {
        // 字符串为空
        if (str.size() == 0)
            return false;
        
        // 去掉首尾空格
        int left = 0, right = str.size() - 1;
        while (str[left] == ' ')
            left++;
        while (str[right] == ' ')
            right--;
        if (left > right)   // 全是空格
            return false;
        str = str.substr(left, right - left + 1);
        
        // 整数部分为有符号整数
        int index = 0;
        bool numeric = scanInteger(str, index);

        // 小数部分为无符号整数
        if (str[index] == '.') {
            index++;
            // numeric = numeric || scanUnsignedInteger(str, index);   // 惰性求值，可能不会进入后面的语句
            numeric = scanUnsignedInteger(str, index) || numeric;
        }

        // 指数部分为有符号整数
        if (str[index] == 'e' || str[index] == 'E') {
            index++;
            numeric = numeric && scanInteger(str, index);
        }
        
        return numeric && (index == str.size());
    }

    bool scanUnsignedInteger(string str, int &index) {
        int before = index;
        while (index < str.size() && str[index] >= '0' && str[index] <= '9')
            index++;
        return index > before;
    }

    bool scanInteger(string str, int &index) {
        if (str[index] == '-' || str[index] == '+')
            index++;
        return scanUnsignedInteger(str, index);
    }
};

int main() {
    Solution s;

    string str = "123.45e+6";
    // string str = ".1";
    // string str = "3.";
    // string str = "  e9   ";

    bool ret = s.isNumeric(str);

    cout << ret << endl;

    return 0;
}