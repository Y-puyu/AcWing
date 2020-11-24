#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10005;

int n, m;
int v[N];
int f[N][N];

int main() {
    cin >> n >> m;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] += f[i - 1][j - v[i]];
        }
    }
    cout << f[n][m] << endl;
    return 0;
}