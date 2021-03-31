// https://www.acwing.com/solution/content/10545/  题解写的相当不错！！！
// 在这的优化空间、时间可真是太秒了
// N = (1+p1+p1^2+...+p1^a1) + (1+p2+p2^2+...+p2^a2) + ...
// 当 p1 是个大素数的时候，那么 N=1+p1，即当 N-1 为素数的时候，里面的一块就只有一项，故可以特判
// 否则，针对每一块都有 N =(1+p1+p1^2+...)      故 sqrt(n) < p1 成立
//                 或者 N =(1+p1)(1+p2+..)      且p1 < p2 ，故 sqrt(n) < sqrt(p1*p2) < p1   
// 故，枚举素数的时候仅需要枚举 sqrt(N) 即可，再针对 N-1 是否为素数的情况作特判，时间复杂度为 sqrt(n)
// 这样 sqrt(2e9) < 50000 ，就极大优化了空间和时间
// 且合法情况很少，暴搜搜索速度很快
// 搜索顺序可以按照约数和乘积中的每一块来搜索
// 搜索每个素数 p，其要保证 p*p <= x
//    再搜索对应的次数 0 1 2 3 4 。。。其要保证当前p 这一乘积块的和小于 x

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50000 + 5;        // sqrt(2e9) 即可，特判质数情况，非质数情况约数一定小于 sqrt(n)

int primes[N], cnt;
bool st[N];
int ans[N], len; 

void getprimes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

bool is_prime(int x) {
    if (x < N) return !st[x];
    for (int i = 0; primes[i] <= x / primes[i]; i ++ )
        if (x % primes[i] == 0)
            return false;
    
    return true;
}

// 从小到大枚举质数，保证不重复
// last 表示上一个枚举的质数下标
// prod 当前的数是多少，即答案，prod 会不断增大，每一次会扩大答案的整数唯一分解定理中的一项，也是约数之和乘积块1+p+p^2..+p^t中最大的一项,p^t
// x 表示要枚举的目标数是多少，x会持续缩小减小规模，即每次减小约数之和乘积中的一项
void dfs(int last, int prod, int x) {
    if (x == 1) {
        ans[len ++ ] = prod;
        return ;
    }
    
    // 这里不能直接 return ; 因为针对 x 只是找到了一个满足特判的素数而已
    // 如 24=1*23 同时它还等于 24=(1+2)(1+7)=(1+3)(1+5); 等情况 分别对应 23 14 15 ,在此return 的话就只剩一种情况了，即最开始的 1 23
    // 因为在下面的话，都是从 1+p 开始枚举的
    if (x - 1 > (last < 0 ? 1 : primes[last]) && is_prime(x - 1))   // 每次需要特判 p=x-1 是否为质数，且要大于上一个枚举的质数,第一个的时候，
        ans[len ++ ] = prod * (x - 1);                              // last=-1, 故 p=x-1 至少为 2 才为质数，否则需要大于上一个质数
    
    for (int i = last + 1; primes[i] <= x / primes[i]; i ++ ) {     // 升序枚举质数，p，枚举约数之和公式中的一块
        int p = primes[i];
        for (int j = 1 + p, t = p; j <= x; t *= p, j += t) {        // 枚举质数p 的最高次数 a，已经在上面特判过了，故在此直接从 1+p，开始枚举
            if (x % j == 0)                                         // j代表质数p这一块的总和，每次加上最高项，p^t 即可
                dfs(i, prod * t, x / j);                            // 当j是x的约数的时候，即x%j==0，此时的p这一块才可能是答案，故dfs再搜
        }
    }
}

int main() {
    getprimes(N - 1);
    
    int x;
    
    while (cin >> x) {
        len = 0;
        dfs(-1, 1, x);      // 质数下标从 0 开始，故 0 的上一个下标为 -1，作为一个特殊情况做特判
        
        cout << len << endl;
        if (len) {
            sort(ans, ans + len);
            for (int i = 0; i < len; i ++ ) cout << ans[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}