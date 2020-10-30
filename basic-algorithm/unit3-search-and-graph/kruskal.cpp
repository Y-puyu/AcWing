#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5+5;

int n, m;
int p[N];

struct Edge {
    int a, b, w;

    bool operator< (const Edge &W) const {
        return w < W.w;                     // 按权重从小到大排序
    }
}edges[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m);

    for (int i = 1; i <= n; ++i) p[i] = i;

    int res = 0, cnt = 0;           // res存最小生成树的权重和，cnt当前加入边的数量
    for (int i = 0; i < m; ++i) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);   // 找到起点a，终点b的祖先

        if (a != b) {               // 如果不在一颗子树内，那么就将其合并。
            p[a] = b;               
            res += w;
            cnt ++;
        }
                                    // 如果在一颗子树内，说明已经连通了，再将该边选入最小生成树则会成环，所以不做操作
    }

    if (cnt < n - 1) puts("impossible");    // n个点的最小生成树应该有n-1条边，如果小于n-1条边则无法构成最小生成树，即无法覆盖所有点
    else cout << res << endl;

    return 0;
}