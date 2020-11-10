#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11005, M = 2005;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int a, b, s;                // 当前物品的 体积 价值 个数
        cin >> a >> b >> s;
        int k = 1;                  // 从 1 开始打包
        while (k <= s) {            
            cnt ++;                 // 记录新打包物品编号，每次打包k个第i个物品
            v[cnt] = a * k;         // k个一组，体积变大k倍
            w[cnt] = b * k;         // k个一组，价值变大k倍
            s -= k;                 // i物品总个数一次性减少k个
            k *= 2;                 // 倍增
        }
        if (s > 0) {                // 补上剩下的物品
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt;    // 更新现在有的物品总数，将其转化为01背包问题，每个物品独立且只能选1次
    
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= v[i]; --j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    cout << f[m] << endl;
    
    return 0;
}