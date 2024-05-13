#include <iostream>
#include <string>

using namespace std;

void test1() {
    // string是C++风格的字符串，本质是一个类
    // C风格的字符串是一个字符数组
    // string和char*的区别
    // 1. char*是一个指针，string是一个类
    // 2. char*需要程序员自己管理内存，string是自动管理内存
    // 3. char*没有提供字符串操作的成员函数，string提供了很多成员函数
    // 4. char*没有操作符重载，string对操作符进行了重载
    // 5. char*没有直接支持输入输出操作，string支持输入输出操作
    
    string str = "Hello, world!";
    cout << str << endl;

    char* p = (char*)"Hello, world!";
    cout << p << endl;
}

void test2() {
    // string构造函数
    // string();  // 创建一个空的字符串 例如: string str;
    // string(const char* s);  // 使用字符串s初始化
    // string(const string& str);  // 使用一个string对象初始化另一个string对象
    // string(int n, char c);  // 使用n个字符c初始化

    string s1;  // 默认构造
    string s2("Hello, world!");  // 有参构造
    string s3(s2);  // 拷贝构造
    string s4(10, 'a');  // 10个a

    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
}

void test3() {
    // string赋值操作
    // string& operator=(const char* s);  // char*类型字符串赋值给当前的字符串
    // string& operator=(const string& s);  // 把字符串s赋给当前的字符串
    // string& operator=(char c);  // 字符赋值给当前的字符串
    // string& assign(const char* s);  // 把字符串s赋给当前的字符串
    // string& assign(const char* s, int n);  // 把字符串s的前n个字符赋给当前的字符串
    // string& assign(const string& s);  // 把字符串s赋给当前字符串
    // string& assign(int n, char c);  // 用n个字符c赋给当前字符串

    string s1;
    s1 = "Hello, world!";
    cout << "s1: " << s1 << endl;

    string s2;
    s2 = s1;
    cout << "s2: " << s2 << endl;

    string s3;
    s3 = 'a';
    cout << "s3: " << s3 << endl;

    string s4;
    s4.assign("Hello, world!");
    cout << "s4: " << s4 << endl;

    string s5;
    s5.assign("Hello, world!", 5);
    cout << "s5: " << s5 << endl;

    string s6;
    s6.assign(s1);
    cout << "s6: " << s6 << endl;

    string s7;
    s7.assign(10, 'a');
    cout << "s7: " << s7 << endl;

}

void test4() {
    // string字符串拼接
    // string& operator+=(const char* s);  // 重载+=操作符
    // string& operator+=(const char c);  // 重载+=操作符
    // string& operator+=(const string& s);  // 重载+=操作符
    // string& append(const char* s);  // 把字符串s连接到当前字符串结尾
    // string& append(const char* s, int n);  // 把字符串s的前n个字符连接到当前字符串结尾
    // string& append(const string& s, int pos, int n);  // 把字符串s中从pos开始的n个字符连接到当前字符串结尾
    // string& append(const string& s);  // 吧字符串s连接到当前字符串结尾
    // string& append(int n, char c);  // 在当前字符串结尾添加n个字符c

    string s1 = "I";
    s1 += " love";
    s1 += ' ';
    s1 += "you";
    cout << "s1: " << s1 << endl;

    string s2 = "I";
    s2.append(" love");
    s2.append(" you");
    cout << "s2: " << s2 << endl;

    string s3 = "I";
    s3.append(" love", 4);
    s3.append(" you");
    cout << "s3: " << s3 << endl;

    string s4 = "I";
    s4.append(s1);
    cout << "s4: " << s4 << endl;

    string s5 = "I";
    s5.append(4, ' ');
    s5.append("love");
    s5.append(1, ' ');
    s5.append("you");
    cout << "s5: " << s5 << endl;

    string s6 = "I";
    s6.append(s1, 2, 4);
    cout << "s6: " << s6 << endl;

}

void test5() {
    // string查找和替换
    // find和rfind的区别: find是从左往右查找, rfind是从右往左查找
    // int find(const string& str, int pos = 0) const;          // 查找str第一次出现位置,从pos开始查找
    // int find(const char* s, int pos = 0) const;              // 查找s第一次出现位置,从pos开始查找
    // int find(const char* s, int pos, int n) const;           // 从pos位置查找s的前n个字符第一次位置
    // int find(const char c, int pos = 0) const;               // 查找字符c第一次出现位置
    // int rfind(const string& str, int pos = npos) const;      // 查找str最后一次出现位置,从pos开始查找
    // int rfind(const char* s, int pos = npos) const;          // 查找s最后一次出现位置,从pos开始查找
    // int rfind(const char* s, int pos, int n) const;          // 从pos查找s的前n个字符最后一次位置
    // int rfind(const char c, int pos = 0) const;              // 查找字符c最后一次出现位置
    // string& replace(int pos, int n, const string& str);      // 替换从pos开始n个字符为字符串str
    // string& replace(int pos, int n, const char* s);          // 替换从pos开始的n个字符为字符串s
    // string& replace(int pos, int n, const char* s, int n2);  // 替换从pos开始的n个字符为字符串s的前n2个字符
    // string& replace(int pos, int n, int n2, char c);         // 替换从pos开始的n个字符为n2个字符c

    string s = "I love you!";
    int pos = s.find("love");
    if (pos == -1) {
        cout << "未找到" << endl;
    } else {
        cout << "找到了,位置为: " << pos << endl;
    }

    int pos2 = s.rfind("you");
    if (pos2 == -1) {
        cout << "未找到" << endl;
    } else {
        cout << "找到了,位置为: " << pos2 << endl;
    }

    // 从pos开始替换n个字符为字符串str，n可以不等于str的长度
    s.replace(2, 4, "hate");
    cout << "s: " << s << endl;
}

void test6() {
    // string比较操作
    // int compare(const string& str) const;  // 与字符串str比较
    // int compare(const char* s) const;  // 与字符串s比较
    // 主要用于比较两个字符串是否相等，比较的是ASCII码值

    string s1 = "xbcdef";
    string s2 = "abcdef";
    if (s1.compare(s2) == 0) {
        cout << "s1等于s2" << endl;
    } else if (s1.compare(s2) > 0) {
        cout << "s1大于s2" << endl;
    } else {
        cout << "s1小于s2" << endl;
    }
}

void test7() {
    // string字符串的存取
    // char& operator[](int n);  // 通过[]方式取字符
    // char& at(int n);  // 通过at方法获取字符

    string s = "abcdef";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < s.size(); i++) {
        cout << s.at(i) << " ";
    }
    cout << endl;

    // 修改
    s[0] = 'x';
    s.at(1) = 'y';
    cout << "s: " << s << endl;

}

void test8() {
    // string字符串的插入和删除
    // string& insert(int pos, const char* s);  // 插入字符串
    // string& insert(int pos, const string& str);  // 插入字符串
    // string& insert(int pos, int n, char c);  // 在指定位置插入n个字符c
    // string& erase(int pos, int n = npos);  // 删除从Pos开始的n个字符

    string s = "abcdef";
    s.insert(1, "111");
    cout << "s: " << s << endl;

    s.insert(1, 3, 'x');
    cout << "s: " << s << endl;

    s.erase(1, 3);
    cout << "s: " << s << endl;

}

void test9() {
    // string字符串的子串
    // string substr(int pos = 0, int n = npos) const;  // 返回由pos开始的n个字符组成的字符串

    string s = "zhangsan@163.com";
    // 截取用户名
    int pos = s.find("@");
    string username = s.substr(0, pos);     // 从0开始截取pos个字符，[0, pos)
    cout << "username: " << username << endl;

    // 截取域名
    string domain = s.substr(pos + 1, s.size() - pos - 1);
    cout << "domain: " << domain << endl;

    

}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    test9();


    return 0;
}
