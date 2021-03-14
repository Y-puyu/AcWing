#if 0

#include <iostream>

using namespace std;

const int N = 1005;

int n, m;
int f[N], v[N], w[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )  cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= v[i]; j -- ) 
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}


#include <iostream>

using namespace std;

const int N = 1005;

int n, m;
int f[N][N], v[N], w[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
        

    cout << f[n][m] << endl;
    return 0;
}

#endif