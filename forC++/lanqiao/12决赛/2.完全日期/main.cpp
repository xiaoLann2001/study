#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sum_of_digit(int y, int m, int d) {
    int sum = 0;
    while (y) {
        sum += (y % 10);
        y /= 10;
    }
    while (m) {
        sum += (m % 10);
        m /= 10;
    }
    while (d) {
        sum += (d % 10);
        d /= 10;
    }
    return sum;
}

int main() {
    // 建完全平方数表
    bool isCompleteNum[37] = {false};
    isCompleteNum[1] = true;
    isCompleteNum[4] = true;
    isCompleteNum[9] = true;
    isCompleteNum[16] = true;
    isCompleteNum[25] = true;
    isCompleteNum[36] = true;

    // 建每个月对应的日期表
    int day_max[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 测试数位和函数
    // cout << sum_of_digit(2001, 1, 1) << endl;

    // 遍历年月日
    int count = 0;
    for (int year = 2001; year <= 2021; year++) {
        for (int month = 1; month <= 12; month++) {
            if (year % 4 == 0 && month == 2) {  // 闰年二月
                for (int day = 1; day <= day_max[month] + 1; day++) {
                    if (isCompleteNum[sum_of_digit(year, month, day)]) count++;
                }
            } else {
                for (int day = 1; day <= day_max[month]; day++) {
                    if (isCompleteNum[sum_of_digit(year, month, day)]) count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}