// 无环连通图，即为 树

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100005;

struct Edge {
    int id, w;
};
int n;
vector<Edge> h[N];
int dist[N];

// 从 u 点到树中各点的距离
void dfs(int u, int fa, int distance) {
    dist[u] = distance;
    
    for (auto e : h[u])                     // 遍历整棵树
        if (e.id != fa)
            dfs(e.id, u, distance + e.w);
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i ++ ) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        h[a].push_back({b, c});
        h[b].push_back({a, c});
    }
    
    dfs(1, -1, 0);  // 从任意一点开始，记录上层父节点防止再回去遍历，保证单方向遍历，记录距离
    
    int u = 1;
    for (int i = 1; i <= n; i ++ )                      // 第一遍先任意一点求出距离最大的一个节点，记为u
        if (dist[i] > dist[u])
            u = i;
    
    dfs(u, -1, 0);
    
    for (int i = 1; i <= n; i ++ )                      // 第二遍以节点u作为根节点求出树的直径
        if (dist[i] > dist[u])
            u = i;
    
    int s = dist[u];
    cout << 10 * s + s * (s + 1ll) / 2 << endl;         // 数字 1 转化为 long long 防止溢出
    
    return 0;
}
