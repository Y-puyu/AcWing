#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e4+5;

int n;
struct Stone {
    int s, e, l;
    bool operator<(const Stone & W) const {
        return s * W.l < l * W.s;
    }
}stone[N];

int f[N];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int m = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int s, e, l;
            cin >> s >> e >> l;
            stone[i] = {s, e, l};
            m += s;
        }
        sort(stone, stone + n);
                                     // 这里的j是吃完这些能量石的s之和,所以是恰好
        memset(f, -0x3f, sizeof f);  // 体积恰好是j,体积越大价值会流失,不一定最好
        f[0] = 0;                    // 初始化负无穷,f[0] = 0
        
        for (int i = 0; i < n; ++i) {
            int s = stone[i].s, e = stone[i].e, l = stone[i].l;
            for (int j = m; j >= s; --j)
                f[j] = max(f[j], f[j - s] + max(0, e - (j - s) * l));   // 不为负数
        }
        int res = 0;
        for (int i = 0; i <= m; ++i) res = max(res, f[i]);
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}