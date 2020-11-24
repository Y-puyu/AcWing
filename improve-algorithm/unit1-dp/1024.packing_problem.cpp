#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20005, M = 35;

int n, m;
int v[N];
int f[M][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> v[i];
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i]);
        }
    }
    cout << n - f[m][n] << endl;
}