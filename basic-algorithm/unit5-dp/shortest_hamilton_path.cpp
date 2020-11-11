#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int w[N][N];
int f[M][N];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> w[i][j];
            
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    
    for (int i = 0; i < 1 << n; ++i)            // 枚举所有路径
        for (int j = 0; j < n; ++j)             // 枚举所有点
            if (i >> j & 1)                     // 如果路径包含该点
                for (int k = 0; k < n; ++k)     // 枚举转移的点
                    if ((i - (1 << j)) >> k & 1)// 除去j点，一定包含k这个点，才能走通
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
    
    cout << f[(1 << n) - 1][n - 1] << endl;     // 走完n个点，且走到第n-1个点的最小值即为答案
    
    return 0;
}