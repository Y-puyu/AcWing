#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 65, M = 32005;

int n, m;   
PII master[N];              // 主件,master.first为体积(钱数),master.second为价值(重要度)
vector<PII> servent[N];     // 附件
int f[M];

int main() {
    cin >> m >> n;      // m总钱数，代表体积，n为个数，代表物品个数
    for (int i = 1; i <= n; ++i) {
        int v, w, q;
        cin >> v >> w >> q;
        if (!q) master[i] = {v, v * w};
        else servent[q].push_back({v, v * w});
    }
    
    for (int i = 1; i <= n; ++i)
        if (master[i].first) {  // 枚举所有的主件.当主件体积为0,则v*w也是0,做不做没啥意义,筛掉
            for (int j = m; j >= 0; --j) // 枚举体积
                for (int k = 0; k < 1 << servent[i].size(); ++k) {  // 二进制枚举所有附件选择情况
                    int v = master[i].first, w = master[i].second;  // 保存当前主件组内选择情况的总体积及总价值
                    for (int u = 0; u < servent[i].size(); ++u) {   // 枚举主件i的所有附件的选择情况
                        if (k >> u & 1) {                           // 如果i主件下附件u被选择
                            v += servent[i][u].first;               // 当前组的体积之和
                            w += servent[i][u].second;              // 当前组的价值之和
                        }
                    }    
                    if (j >= v) f[j] = max(f[j], f[j - v] + w);     // j体积够用,则状态转移
                }
        }
        
    cout << f[m] << endl;
    
    return 0;
}