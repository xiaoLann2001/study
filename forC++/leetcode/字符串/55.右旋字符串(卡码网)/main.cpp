// 字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。

// 给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的

// 后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。 

// 例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。

#include <iostream>
#include <string>

#include <algorithm>

using namespace std;

int main() {
    string s;
    int k;
    
    cin >> k;
    cin >> s;

    reverse(s.begin(), s.end());

    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());

    cout << s << endl; 
}