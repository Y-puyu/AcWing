#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1005;

int n;
char g[N][N];
bool st[N][N];
PII q[N * N];
int total, bound;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(int sx, int sy) {
    total = 0, bound = 0;
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;
    
    while (hh <= tt) {
        auto t = q[hh ++];
        total ++ ;
        
        bool is_bound = false;
        for (int i = 0; i < 4; i ++ ) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= n || st[x][y]) continue;
            if (g[x][y] == '.') {
                is_bound = true;
                continue;
            }
            q[ ++ tt ] = {x, y};
            st[x][y] = true;
        }
        
        if (is_bound) bound ++ ;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> g[i];
    
    int res = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ ) {
            if (g[i][j] == '#' && !st[i][j]) {
                bfs(i, j);
                if (total == bound) res ++ ;
            }
        }
        
    cout << res << endl;
    
    return 0;
}


//
// 理解 dfs 与 bfs 的搜索都是连通的

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;
char g[N][N];
bool st[N][N];
int flag;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int sx, int sy) {
    st[sx][sy] = true;
    if (g[sx + 1][sy] == '#' && g[sx - 1][sy] == '#' && g[sx][sy + 1] == '#' && g[sx][sy - 1] == '#' ) flag = true; // 只要陆地被包围，该连通块有效
    
    for (int i = 0; i < 4; i ++ ) {
        int x = sx + dx[i], y = sy + dy[i];
        if (!st[x][y] && g[x][y] == '#') dfs(x, y);         // 继续 dfs 未标记的陆地，为的是标记它们
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> g[i];
    
    int res = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ ) {
            if (g[i][j] == '#' && !st[i][j]) {          // 是陆地块，并且未被判断搜索过的话
                flag = false;
                dfs(i, j);                              // dfs 搜索其所在的连通块
                if (!flag) res ++ ;                     
            }
        }
        
    cout << res << endl;
    
    return 0;
}