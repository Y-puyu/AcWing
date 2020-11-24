#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105, INF = 1e9;

int n;
int w[N][N];
int f[N][N];

int main() {
    memset(f, 0x3f, sizeof f);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j)
            scanf("%d", &w[i][j]);
    
    f[0][0] = f[1][0] = f[0][1] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            f[i][j] = min(f[i][j - 1], f[i - 1][j]) + w[i][j];
            
    printf("%d", f[n][n]);
    return 0;
}