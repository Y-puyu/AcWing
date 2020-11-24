#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005, M = 505, K = 105;
const int INF = 0x3f3f3f3f;

int n, m, t;
int f[M][K];

int main() {
    cin >> n >> m >> t;
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < t; ++i) f[i][0] = 0;    // 不收服精灵,则不用精灵球,故初始化为0
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = m; j >= b; --j) 
            for (int k = t; k >= 1; --k) 
                if (f[j - b][k - 1] + a <= n)
                    f[j][k] = min(f[j][k], f[j - b][k - 1] + a);
    }
    for (int k = t; k >= 0; --k) {              // 逆序枚举精灵最大只数
        int p = INF;
        for (int j = 0; j < m; ++j)             // 体积从0~m-1,顺序枚举
            if (f[j][k] != INF && j < p)// 若发生转移且体积有更新,则获得最小体积下的最大收服精灵数
                p = j;
        
        if (p != INF) {
            cout << k << ' ' << m - p << endl;
            return 0;
        }
    }
    return 0;
}