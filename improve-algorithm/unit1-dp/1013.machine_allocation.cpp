#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15, M = 20;

int n, m;
int w[N][M];
int f[N][M];
int way[N][M];

// 递归求方案
void print(int x, int y) {
    if (x == 0) return ;
    int k = way[x][y];
    print(x - 1, y - k);
    cout << x << ' ' << k << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j)
            cin >> w[i][j];
    
    for (int i = 1; i <= n; ++i)            // 枚举组
        for (int j = 0; j <= m; ++j) {      // 枚举体积
            f[i][j] = f[i - 1][j];          // 一个都不选的情况,在本题其实不用考虑该情况
            for (int k = 1; k <= j; ++k)    // 枚举物品,数量和价值在此统一到一起表示
                if (f[i][j] <= f[i - 1][j - k] + w[i][k]) {
                    f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
                    way[i][j] = k;          // 存i公司分配j台机器的最优解时第i个公司分配了几台机器
                }
        }
        
    cout << f[n][m] << endl;

    print(n, m);
    
    for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= m; ++j)
            cout << way[i][j] << ' ';
            cout << endl;
    }

    return 0;
}