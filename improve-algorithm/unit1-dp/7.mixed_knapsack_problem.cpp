#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, m;
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)  {
        int v, w, s;
        cin >> v >> w >> s;
        if (s == 0) {                                       // 完全背包
            for (int j = v; j <= m; ++j) 
                f[j] = max(f[j], f[j - v] + w);
        } else {
            if (s == -1) s = 1;                             // 01背包就是多重背包数量为1的情况
            for (int k = 1; k <= s; k *= 2) {               // 多重背包二进制优化
                for (int j = m; j >= k * v; --j) 
                    f[j] = max(f[j], f[j - k * v] + k * w);
                s -= k;
            }
            if (s) {                                        // 处理剩下的物品个数
                for (int j = m; j >= s * v; --j) 
                    f[j] = max(f[j], f[j - s * v] + s * w);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}