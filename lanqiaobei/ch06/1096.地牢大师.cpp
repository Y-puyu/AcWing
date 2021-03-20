#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;

struct Point {
    int x, y, z;
};
int L, R, C;
char g[N][N][N];
int dist[N][N][N];
Point q[N * N * N];

int dx[6] = {1, -1, 0, 0, 0}, dy[6] = {0, 0, 1, -1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};     // 三维偏移 

int bfs(Point start, Point end) {
    int hh = 0, tt = 1;
    q[0] = start;
    memset(dist, -1, sizeof dist);
    dist[start.x][start.y][start.z] = 0;
    
    while (hh < tt) {
        auto t = q[hh ++];
        
        for (int i = 0; i < 6; i ++ ) {
            int x = t.x + dx[i], y = t.y + dy[i], z = t.z + dz[i];
            if (x < 0 || x >= L || y < 0 || y >= R || z < 0 || z >= C || g[x][y][z] == '#' || dist[x][y][z] != -1) continue;
            
            dist[x][y][z] = dist[t.x][t.y][t.z] + 1;
            
            if (x == end.x && y == end.y && z == end.z) return dist[x][y][z];
            
            q[tt ++ ] = {x, y, z};
        }
    }
    
    return -1;
}

int main() {
    while (cin >> L >> R >> C, L || R || C) {
        Point start, end;
        for (int i = 0; i < L; i ++ ) {         // 第一次这样的形式读入，回想一下其实都是很自由的，不一定非要 严格 按照行列来进行存储
            for (int j = 0; j < R; j ++ ) {
                cin >> g[i][j];
                for (int k = 0; k < C; k ++ ) {
                    if (g[i][j][k] == 'S') start = {i, j, k};
                    else if (g[i][j][k] == 'E') end = {i, j, k};
                }
            }
        }
        int distance = bfs(start, end);
        if (distance == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << distance << " minute(s)." << endl;
    }
    
    return 0;
}