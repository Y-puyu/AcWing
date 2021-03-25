// 贪心，通过一个最大值-（最小值） 的操作，可以构建出来 1~M+N 个负号
// 即任意数字可以任意填
// 主要分三种情况考虑
// M = 0 即没有负号，全部累加即可
// M > 0 N = 0 全为负号，其实能够通过加括号的形式构建出 1~M 个负号
// M > 0 N > 0 能够将正号放到括号内变负号，能够构建出 1~M+N 个负号。即有了最大值，最小值，一个负号后
// 正数可以直接 + 放到括号外，也可以 - 放到括号内
// 负数可以直接 - 放到括号外将其变为正数，也可以 + 放到括号内，最后变为正数
// 故任意数字均可去到正值最大值
// 但需要注意一定是要提前 +最大值，-最小值。。。被坑了一道。。。没考虑 +最大值的情况，负号前面也得有一个操作数才行
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, m;
int a[N];

int main() {
    cin >> n >> m;
    int k = n + m + 1;
    for (int i = 0; i < k; i ++ ) cin >> a[i];
    
    sort(a, a + k);
    
    LL res = 0;
    if (!m) {                       // 特判没有建好的情况，所有的数字都得累加起来
        for (int i = 0; i < k; i ++ ) res += a[i];
    } else {
        res -= a[0], res += a[k - 1];   // 形如 max - (mi -。。+ ) + ...仅需一个最大值，一个最小值，一个负号。那么其余数字想加就加，想减就减
        for (int i = 1; i < k - 1; i ++ ) res += abs(a[i]); 
    }
    cout << res << endl;
    return 0;
}