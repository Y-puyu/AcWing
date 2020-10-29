#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 505, M = 1e5+10;

int n, m, k;
int dist[N], backup[N];

struct Edge {
    int a, b, w;
}edges[M];

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < k; ++i) {
        memcpy(backup, dist, sizeof dist);      // 备份backup数组，用以更新，避免串联
        for (int j = 0; j < m; ++j) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    
    if (dist[n] > 0x3f3f3f3f / 2) return -1;    // 最多也就减500*10000
    return dist[n];
}

int main() {
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    
    int t = bellman_ford();
    
    if (t == -1) puts("impossible");
    else cout << t << endl;
    return 0;
}