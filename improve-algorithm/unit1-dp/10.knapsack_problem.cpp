#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;

int n, m;
int v[N], w[N];
int h[N], e[N], ne[N], idx;
int f[N][N];                            // 虽然开了二维，不过第一维是根节点数，对于分组背包部分来说还是一维，需要逆序体积

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
    for (int i = h[u]; ~i; i = ne[i]) { // 循环物品组,遍历u号点的所有子树,~i表示i!=-1,因为~(-1) = 0
        int son = e[i];                 // 子节点编号
        dfs(e[i]);                      // 递归所有子树，得到所有子节点的f值
        
        // 分组背包
        // 这里对于树中的每个节点来说，就是一个分组背包问题。每个子节点是一组，
        // 每个子节点的不同体积和每个体积所对应的最大价值，就是这个物品组中的选出的物品
        for (int j = m - v[u]; j >= 0; --j)     // 循环体积,根节点一定被先选,留出u的体积。这里是逆序体积，
            for (int k = 0; k <= j; ++k)        // 循环决策,根据体积分割集合,故为0~j
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);    // f[son][k]代表的是当前子节点k决策的价值
    }
    
    for (int i = m; i >= v[u]; --i) f[u][i] = f[u][i - v[u]] + w[u];    // 得加上根节点的价值
    for (int i = 0; i < v[u]; ++i) f[u][i] = 0;                         // 若根节点放不下，则依赖关系不满足，该得到的价值失效
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h); 
    int root;
    for (int i = 1; i <= n; ++i) {  // 读取n个物品
        int p;                      // p为第i个物品的依赖物品编号,可以理解为父节点
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;      // 存根节点
        else add(p, i);             // p指向i的边,父节点指向i这个子节点
    }
    
    dfs(root);
    
    cout << f[root][m] << endl;
    
    return 0;
}
