#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 11, M = 1 << 10;

int n, m;
int g[105];
vector<int> state;
int cnt[M];
int f[2][M][M];     // 使用滚动数组,后两维都已经100w了...

bool check(int x) {
    for (int i = 0; i < m; ++i)         // 针对列做状态压缩,同列三个不能有2个1
        if ((x >> i & 1) && ((x >> i + 1 & 1) | (x >> i + 2 & 1)))
            return false;

    return true;
}

int count(int x) {
    int res = 0;
    for (int i = 0; i < m; ++i) res += x >> i & 1;
    return res;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < m; ++j) {
            char c;                     // 拿int类型读入char,读入全是0
            cin >> c;
            if (c == 'H')
                g[i] += 1 << j;         // 二进制表示一行
        }

    for (int i = 0; i < 1 << m; ++i) 
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }

    for (int i = 1; i <= n + 2; ++i)
        for (int j = 0; j < state.size(); ++j)              // j为第i-1行状态
            for (int k = 0; k < state.size(); ++k)          // k为第i行状态
                for (int u = 0; u < state.size(); ++u) {    // u为第i-2行状态
                    int a = state[j], b = state[k], c = state[u];
                    if ((a & b) | (b & c) | (a & c)) continue;
                    if (g[i - 1] & a | g[i] & b) continue;
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
                }

    cout << f[n + 2 & 1][0][0] << endl;


    // 遍历写法，修改第一个 for (int i = 1; i <= n; ++i)
    /*
    int res = 0;
    for (int i = 0; i < state.size(); ++i) 
        for (int j = 0; j < state.size(); ++j)
            res = max(res, f[n & 1][i][j]);
    cout << res << endl;
    */

    return 0;
}