#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;
int a[N], f[N], g[N];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        g[i] = 0;       // 表示它只有一个数
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j]) 
                if (f[i] < f[j] + 1) {
                    f[i] = max(f[i], f[j] + 1);
                    g[i] = j;       //记录下是从哪里转移过来的
                }
        }
    }
    
    int k = 1;                      
    for (int i = 1; i <= n; ++i)    // 找到f[i]数组最大值，即最长上升子序列长度
        if (f[k] < f[i])
            k = i;                  // k保存f[i]最大值的下标
    
    cout << f[k] << endl;           // f[k]即为最长上升子序列的最大长度
    
    for (int i = 0, len = f[k]; i < len; ++i) {   // 逆序输出方案
        cout << a[k] << ' ';
        k = g[k];
    }
    return 0;
}