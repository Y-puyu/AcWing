#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5+5, M = 105, INF = 0x3f3f3f3f;

int n, k;
int a[N];
int f[N][M][2];

int main() {
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    memset(f, 0xcf, sizeof f);
    for (int i = 0; i <= n; ++i) f[i][0][0] = 0;
    
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= k; ++j) {
            f[i][j][0] = max(f[i - 1][j][1] + a[i], f[i - 1][j][0]);
            f[i][j][1] = max(f[i - 1][j - 1][0] - a[i], f[i - 1][j][1]);
        }
    
    int res = 0;
    for (int i = 0; i <= k; ++i) res = max(res, f[n][i][0]);    // f[n][i][0]是完整交易
    cout << res << endl;
    
    return 0;
}