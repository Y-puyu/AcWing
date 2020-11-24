#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;
int a[N], g[N];
int f[N];

int main() {
    while (cin >> a[n]) ++n;                    // 得到输入数字的个数
    
    int res = 0;
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[i] <= a[j])                   // 在此求最长下降子序列
                f[i] = max(f[i], f[j] + 1);
        
        res = max(res, f[i]);
    }
    cout << res << endl;
    
    int cnt = 0;                                // 记录所有子序列末尾数字
    for (int i = 0; i < n; ++i) {
        int k = 0;
        while (k < cnt && g[k] < a[i]) ++k;     // 找到第一个比自己
        g[k] = a[i];
        if (k >= cnt) cnt ++;
    }
    cout << cnt << endl;
    return 0;
}