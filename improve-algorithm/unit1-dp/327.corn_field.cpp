#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 14, M = 1 << 12, MOD = 1e8;

int n, m;
int g[N];               // 将地图每一行抽象为二进制表示
vector<int> state;
vector<int> head[M];
int f[N][M];

bool check(int x) {
    for (int i = 0; i + 1< m; ++i) 
        if ((x >> i & 1) && (x >> i + 1 & 1))
            return false;

    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) 
        for (int j = 0; j < m; ++j) {
            int t;
            cin >> t;
            g[i] += !t << j;            // 很巧妙,是1的地方不能选,方便做&运算
        }

    for (int i = 0; i < 1 << m; ++i)
        if (check(i))
            state.push_back(i);

    for (int i = 0; i < state.size(); ++i)
        for (int j = 0; j < state.size(); ++j) {
            int a = state[i], b = state[j];
            if ((a & b) == 0) 
                head[i].push_back(j);               // 下标映射
        }

    f[0][0] = 1;
    for (int i = 1; i <= n + 1; ++i)
        for (int a = 0; a < state.size(); ++a)
            for (int b : head[a])
                if ((g[i] & state[a]) == 0)
                    f[i][a] = (f[i][a] + f[i - 1][b]) % MOD;

    cout << f[n + 1][0] << endl;
    return 0;
}