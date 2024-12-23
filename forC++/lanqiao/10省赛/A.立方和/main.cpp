#include <iostream>
#include <unordered_set>
//#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	// 建立哈希集合，便于查找
	unordered_set<int> uset;
	uset.insert(2);
	uset.insert(0);
	uset.insert(1);
	uset.insert(9);
	
	long long sum = 0;
	// 遍历1~2019查询是否为哈希集合中的元素 
	for (int i = 1; i <= 2019; i++) {
		// 分离数位分别做判断
		int temp = i;
		while (temp != 0) {
			if (uset.find(temp % 10) != uset.end()) {
				sum += (i * i * i);
				break;
			}
			temp /= 10;
		} 
	}
	
	cout << sum << endl;
	
	return 0;
}