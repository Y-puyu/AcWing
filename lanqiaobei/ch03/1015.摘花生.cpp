#include <iostream>

using namespace std;

const int N = 105;

int n, m;
int f[N][N], g[N][N];

int main() {
    int T;
    cin >> T;
    
    while (T -- ) {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m ; j ++ )
                cin >> g[i][j];
        
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];
        
        cout << f[n][m] << endl;
    }
    return 0;
}