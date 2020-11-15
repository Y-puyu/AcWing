#include <iostream>
#include <cstring> 
#include <algorithm>

using namespace std;

const int N = 305;

int n, m;
int h[N][N];
int res = -1;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int len) {
    if (res < len) res = len;
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y])
            dfs(a, b, len + 1);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> h[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int len = 1;
            dfs(i, j, len);
        }

    cout << res << endl;

    return 0;
}