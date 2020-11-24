#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3005;

int n;
int a[N], b[N];
int f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    
    for (int i = 1; i <= n; ++i) {
        int maxv = 1;
        for (int j = 1; j <= n; ++j) {
            f[i][j] = f[i - 1][j];      // 枚举所有不包含a[i]的上升公共子序列
            // 枚举所有包含a[i]，且以a[j]结尾的最长公共上升子序列
            // 前i个字母包含a[i]，且以b[j]结尾，所有当b[j]<a[i]的过程就是从1~j-1枚举k的过程
            // b[j]的序列也是单调上升的，所以b[j]<a[i]就不会让j取到i这个位置
            // 所以在此是动态更新1~j-1的最小值
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);      // 顺带更新空集
            if (b[j] < a[i]) maxv = max(maxv, f[i - 1][j] + 1);  // a[i]已经被使用，只能从a[1~i-1]中选,符合状态定义
        }                                                        // 其实在此因为b[j]<a[i],说明a[i]!=b[j],所以直接拿f[i][j]更新也是正确的
    }
        
    int res = 0;
    for (int i = 1; i <= n; ++i) res = max(res, f[n][i]);
    cout << res << endl;
    return 0;
}