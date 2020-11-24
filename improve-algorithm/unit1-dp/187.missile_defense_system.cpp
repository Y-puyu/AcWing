#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int q[N];
int up[N], down[N];
int ans;

// u:当前枚举到那个数,su:最小上升子序列个数,sd最小下降子序列个数
void dfs(int u, int su, int sd) {   
    if (su + sd >= ans) return ;    // su和sd不会再将答案变小，故剪枝，以此找到最小值
    if (u == n) {
        ans = su + sd;      // 枚举结束，直接更新，因为su+sd>n的情况已经提前return了
        return ;
    }
    
    // 情况1：将当前数放到下降子序列中
    int k = 0;
    while (k < su && up[k] >= q[u]) k ++;
    int t = up[k];                  // 现场备份，方便回溯时恢复现场
    up[k] = q[u];                   
    if (k < su) dfs(u + 1, su, sd);
    else dfs(u + 1, su + 1, sd);
    up[k] = t;                      // 恢复现场
    
    // 情况2：将当前数放到上升子序列中
    k = 0;
    while (k < sd && down[k] <= q[u]) k ++;
    t = down[k];
    down[k] = q[u];
    if (k < sd) dfs(u + 1, su, sd);
    else dfs(u + 1, su, sd + 1);
    down[k] = t;                    // 恢复现场
}

int main() {
    while (cin >>n, n) {
        for (int i = 0; i < n; ++i) cin >> q[i];
        
        ans = n;        // 最坏情况每个数单独一个序列，则最大为n
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}