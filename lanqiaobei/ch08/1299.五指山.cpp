// 裴蜀定理---扩展欧几里得算法
// 求不定方程的整系数，ax+by=z 当 z % (a, b) == 0 时，有整系数 x， y 存在。扩展欧几里得可求
// 注意通解的表示，b = b0+kn/(a,b) 等价于 (b0%n+n)%n 求出 b 的最小正整数解

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return d;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T -- ) {
        LL n, d, x, y, a, b;
        scanf("%lld%lld%lld%lld", &n, &d, &x, &y);
        int gcd = exgcd(n, d, a, b);
        if ((y - x) % gcd != 0) puts("Impossible");
        else {
            a *= (y - x) / gcd, b *= (y - x) / gcd;
            n /= gcd;
            printf("%d\n", (b % n + n) % n);
        }
    }
    return 0;
}


