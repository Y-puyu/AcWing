#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 505, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1; 
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        if (i && dist[t] == INF) return INF;    // 不是第一个点且到集合距离为INF，说明该点不连通

        // 在此累加需要放到更新之前，数据可能会出现自负环
        // 即g[t][t] = -10，他会将dist[t]更新为-10，导致后续累加边权错误
        // 但是最小生成树中是不包括自环的，需注意
        if (i) res += dist[t];                  // 连通，作为生成树的某一条边

        for (int j = 1; j <= n; ++j)            // 更新其他点到集合外各点的距离
            dist[j] = min(dist[j], g[t][j]);    // 注意更新距离的方式

        st[t] = true;                           // 加入集合
    }
    return res;
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);


    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    if (t == INF) puts("impossible");
    else cout << t << endl;

    for (int i = 1; i <= n; ++i) cout << dist[i] << ' ';

    return 0;
}