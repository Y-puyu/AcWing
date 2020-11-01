#include <iostream>
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
    int n;
    cin >> n;

    LL x = 0, a1, m1;   // x作为当前是否无解
    cin >> a1 >> m1;    // 读入第一个方程
    for (int i = 0; i < n - 1; ++i) {   // 读入后续n-1个方程
        LL a2, m2;
        cin >> a2 >> m2;
        LL k1, k2;          
        LL d = exgcd(a1, -a2, k1, k2);  // 扩欧计算k1, k2,在此a2正负无所谓,不影响最大公约数的计算
        if ((m2 - m1) % d) {    // 扩欧有解的充要条件
            x = -1;
            break;
        }

        k1 *= (m2 - m1) / d;    // 等式恒等变换,翻转为m2-m1为等式右边项，以前是d为等式右边项
        k1 = (k1 % (a2/d) + a2/d) % (a2/d); // 另k1变成方程的最小正整数解

        x = k1 * a1 + m1;  // x的所有解

        LL a = abs(a1 / d * a2);  // 临时变量a存一下变化a的值，清晰点
        m1 = k1 * a1 + m1;  // 更新m1，其实就是x
        a1 = a; // a1 更新为a
    }

    if (x != -1) x = (x % a1 + a1) % a1;  // 最小正余数

    cout << x << endl;

    return 0;
}