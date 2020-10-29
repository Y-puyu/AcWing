#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6+5;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

// 和堆优化dijkstra算法很相似，直接cv过去就能过掉
int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;
    
    while (q.size()) {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i]) {    // 更新t的所有出边
            int j = e[i];                           // j表示当前这个点        
            if (dist[j] > dist[t] + w[i]) {         
                dist[j] = dist[t] + w[i];           
                if (!st[j]) {                       // 可更新，入队
                    q.push(j);
                    st[j] == true;
                }
            }
        }
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    int t = spfa();
    if (t == -1) puts("impossible");
    else cout << t << endl;
    
    return 0;
}
