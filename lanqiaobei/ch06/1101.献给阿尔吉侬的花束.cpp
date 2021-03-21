#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 205;

int n, m;
char g[N][N];
int dist[N][N];     // 距离+判重

int bfs(PII start, PII end) {
    queue<PII> q;
    q.push(start);
    
    memset(dist, -1, sizeof dist);              // 三种状态，-1 不可到达，0 起点，i 终点
    
    dist[start.x][start.y] = 0;
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    while (q.size()) {
        PII t = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i ++ ) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#' || dist[x][y] != -1) continue;
            
            dist[x][y] = dist[t.x][t.y] + 1;
            
            if (make_pair(x, y) == end) return dist[x][y];      // 不能直接 {x,y} == end 需要将其转换为 pair
            
            q.push({x, y});
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    
    while (T -- ) {
        cin >> n >> m;
        
        for (int i = 0; i < n; i ++ ) scanf("%s", &g[i]);
        
        PII start, end;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if (g[i][j] == 'S') start = {i, j};
                else if (g[i][j] == 'E') end = {i, j};
            }
        
        int res = bfs(start, end);
        if (res == -1) cout << "oop!" << endl;
        else cout << res << endl;
    }
    
    return 0;
}