// 均值不等式，数学推公式
// 每个人尽量付平均，使得方差最小，数据离散程度最小
// 排序后方便操作
// 不足平均的，自己全付完，总钱数缩小 ai，人数 -1，问题缩小为子问题继续求解平均数，继续对待下一个人
// 排序后半段一定可以全部支付完毕
//
// 理解一点，这里的每人付的平均数是动态平均数，即下一个人付多少根据前一人是否付满平均数决定 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5e5 + 5;

int n;
double s;           // 坑点。。。int / int = int，即便是double 也在运算过程中将小数部分舍去了，向下取整
int a[N];

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    sort(a, a + n);
    
    double res = 0, avg = s / n;
    for (int i = 0; i < n; i ++ ) {
        double cur = s / (n - i);               // 当前人理应付的最佳钱数，s 为后半段 n-i 个人的付钱总和。不足，全付，足，只付cur
        if (a[i] < cur) cur = a[i];
        res += (cur - avg) * (cur - avg);
        s -= cur;
    }
    printf("%.4lf\n", sqrt(res / n));
    return 0;
}