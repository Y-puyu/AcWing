// bfs
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 25;

int n, m;
char g[N][N];
bool st[N][N];

int main() {
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < m; i ++ ) cin >> g[i];
        
        PII start;
        for (int i = 0; i < m; i ++ ) 
            for (int j = 0; j < n; j ++ ) {
                if (g[i][j] == '@') start = {i, j};
            }
        
        queue<PII> q;
        q.push(start);
        st[start.x][start.y] = true;
        
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        int res = 1;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i ++ ) {
                int a = t.x + dx[i], b = t.y + dy[i];
                if (a < 0 || a >= m || b < 0 || b >= n || g[a][b] != '.' || st[a][b]) continue;
                
                res ++ ;
                st[a][b] = true;
                q.push({a, b});
            }
        }
        cout << res << endl;
        
        memset(st, 0, sizeof st);
    }
    return 0;
}

//dfs
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 25;

int n, m;
char g[N][N];
bool st[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    int cnt = 1;
    st[x][y] = true;
    for (int i = 0; i < 4; i ++ ) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] != '.' || st[a][b]) continue;
        cnt += dfs(a, b);
    }
    return cnt;
}

int main() {
    while (cin >> m >> n, n || m) {
        for (int i = 0; i < n; i ++ ) cin >> g[i];
        
        int x, y;
        for (int i = 0; i < n; i ++ )   
            for (int j = 0; j < m; j ++ ) 
                if (g[i][j] == '@')
                    x = i, y = j;

        memset(st, 0, sizeof st);
        
        cout << dfs(x, y) << endl;
    }
    
    return 0;
}