#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005, MOD = 1e9+7;

int n, m;
int f[N];
int g[N];

int main() {
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0] = 1;
    g[0] = 1;
    for (int i = 0; i < n; ++ i) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; -- j) {
            int maxv = max(f[j], f[j - v] + w);
            int cnt = 0;
            if (maxv == f[j]) g[j] = g[j] % MOD;
            if (maxv == f[j - v] + w) g[j] = g[j - v] % MOD;
            f[j] = maxv;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= m; ++i) cnt = max(cnt, f[i]);

    int res = 0;
    for (int j = 0; j <= m; ++j)     
        if (cnt == f[j])
            res = (res + g[j]) % MOD;
    cout << res << endl;
    return 0;
}