#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    // for (int i = 2; i <= num / 2; i++) {
    // for (int i = 2; i <= sqrt(num); i++) {
    for (int i = 2; i * i < num; i++) { // 瓶颈1：找质数时，只需遍历到平方根初即可
        if (num % i == 0) return false; // 若除了1和自身还能被其它数整除，说明是合数
    }
    return true;
}

// 优化：用埃氏筛法获得质数哈希表
void sieve(int num, vector<bool>& is_prime)
{
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= num; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= num; j += i) { // 所有能被i整除的数为合数
                is_prime[j] = false;
            }
        }
    }
}

int main()
{
    int count = 0;
    int hashmap[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0}; // 2,3,5,7
    vector<bool> is_prime(20210605 + 1, true);   // 查质数哈希表
    sieve(20210605, is_prime);

    for (int i = 2; i <= 20210605; i++) {
        // 先判断所有数位符不符合条件
        int shift = 1;
        while ((i / shift) != 0) {
            int digit = (i / shift) % 10;
            // 优化：用哈希表查找元素是否出现
            if (!hashmap[digit])
                break;
            // 瓶颈2：多次判断元素是否出现比较费时
            // if ((digit != 2) && (digit != 3) && (digit != 5) && (digit != 7)) break;
            shift *= 10;
        }
        // 若所有数位都满足条件，再判断是不是质数
        if (0 == (i / shift)) {
            // if (isPrime(i))
            if (is_prime[i])    // 优化：快速判断是否为质数
                count++;
        }
    }
    cout << count << endl;
    return 0;
}