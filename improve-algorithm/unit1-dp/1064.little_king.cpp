#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << 10, K = 110;

int n, m;
vector<int> state;          // 表示所有合法状态,不存在连续两个1的状态
vector<int> head[M];        // 每个状态可以转移到的其他状态
int cnt[M];                 // 每个状态1的个数
LL f[N][K][M];

bool check(int x) {
    for (int i = 0; i < n; ++i)
        if ((x >> i & 1) && (x >> i + 1 & 1))
            return false;
    return true;
}

int count(int x) {
    int res = 0;
    for (int i = 0; i < n; ++i) 
        if (x >> i & 1)
            ++ res;
    return res;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < 1 << n; ++i) 
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }
    
    for (int i = 0; i < state.size(); ++i) 
        for (int j = 0; j < state.size(); ++j) {
            int a = state[i], b = state[j];         // 建立状态之间可以相互转化的映射关系
            if ((a & b) == 0 && check(a | b))
                head[i].push_back(j);
        }
    
    // 一行没摆,一个国王没有,只有状态0合法,为一种方案
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; ++i)    
        for (int j = 0; j <= m; ++j)
            for (int a = 0; a < state.size(); ++a)              // 枚举所有合法状态
                for (int b = 0; b < head[a].size(); ++b) {      // 枚举所有可以抵达的合法状态
                    int c = cnt[state[a]];
                    if (j >= c) 
                        f[i][j][state[a]] += f[i - 1][j - c][state[head[a][b]]];
                }
    
    // 技巧：摆到n+1行中共m个国王,且n+1行一个国王都没摆的所有方案
    // 和n行m个国王的所有方案是等价的
    cout << f[n + 1][m][0] << endl;
    return 0;
}
