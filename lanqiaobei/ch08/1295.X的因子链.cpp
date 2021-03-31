// 很不错的一道题
// 1. 线性筛。可维护每一个数的最小质因子是多少，中间能求出来很多信息
// 2. 多重集组合数。1 2 2 3 3 3 总共6个数，求其有多少组互不相同的组合种类  6!/(2!*3!)
//    n 个数的组合总数就是 n * n-1 * n-2 *...* 2 * 1 = n!
//    但里面有重复的元素，每一个互不相同的组合中，相同的数位置都可以互相发生变化，由乘法原理可得相同的组合类型为 n1!*n2!*...*nm!，ni 为相同数的个数
//    故不同组合的重复数固定，总数固定，则可求出互不相同的组合种类数，简单做除法即可
// 3. 算术基本定理。
// 4. 质因子分解。通过每个数的最小质因子能快速进行质因子分解

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = (1 << 20) + 5;

int n;
int primes[N], cnt;
bool st[N];
int minp[N];
int fact[25], sum[25];       // 记录因子和因子次数，最多是，2^20 20 个 2，2有20个

void getprimes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) minp[i] = i, primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            minp[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

LL getfact(int n) {
    LL res = 1;
    for (LL i = 1; i <= n; i ++ ) {
        res *= i;
    }
    return res;
}

int main() {
    getprimes(N - 1);
    while (cin >> n) {
        int k = 0, tot = 0;
        while (n > 1) {                         // 分解质因数。线性筛处理得到了每一个数的最小质因数，就可以拿这个方式来分解质因数及对应次数
            int p = minp[n];                    // 每次分解最小的质因数，将其处理完毕，思想很不错
            fact[k] = p, sum[k] = 0;            // 最小质因数为p，初始次数为 0，方便 while 循环处理
            while (n % p == 0) {
                n /= p;
                sum[k] ++ ;
                tot ++ ;                        // 记录所有的次数之和
            }
            k ++ ;
        }
        
        LL a = getfact(tot);                    // 预处理 20 内的阶乘也是很不错的 fact[i] = fact[i - 1] * i;
        LL b = 1;
        for (int i = 0; i < k; i ++ ) b *= getfact(sum[i]);
        
        cout << tot << ' ' << a / b << endl;
    }
    return 0;
}