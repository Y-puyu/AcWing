// 很不错的题，一开始考虑单调递增不好实现，没想到放到了转移过程中，用状态的成功转移保证了单调递增

#include <iostream>

using namespace std;

const int N = 55, MOD = 1e9 + 7;        // 针对1e9+7的取余，最多只能相加两个数就得取余，三个数即3*MOD将爆掉int

int n, m, k;
int w[N][N], f[N][N][13][14];           // 到达第i,j点时去了k件物品且最大价值是c的方案总数，枚举c取最大就是答案

int main() {
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) {
            cin >> w[i][j];         // 所有物品价值变为 1~13
            w[i][j] ++ ;
        }
    
    f[1][1][1][w[1][1]] = 1, f[1][1][0][0] = 1;
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ ) {
            if (i == 1 && j == 1) continue;                 // 针对第一个宝物取不取已经初始化，这个没考虑到，并不影响ac
            for (int p = 0; p <= k; p ++ )
                for (int q = 0; q <= 13; q ++ ) {
                    int &val = f[i][j][p][q]; 
                    val = (val + f[i - 1][j][p][q]) % MOD;  // 不取的两种情况
                    val = (val + f[i][j - 1][p][q]) % MOD;
                    if (p >= 1 && q == w[i][j]) {            // 取w[i][j]的两种情况，p至少为1，即至少取w[i][j]这件物品，q就是w[i][j]
                        for (int c = 0; c < q; c ++ ) {     // 枚举小于w[i][j]的所有取法总数，其这一步就是w[i][j]最大，成功转移保证单调递增
                            val = (val + f[i - 1][j][p - 1][c]) % MOD;
                            val = (val + f[i][j - 1][p - 1][c]) % MOD;
                        }
                    }
                }
        }
    
    int res = 0;
    for (int i = 0; i <= 13; i ++ ) res = (res + f[n][m][k][i]) % MOD;      // 循环初值 0 1 均可，f[n][m][k][0] = 0; 没有物品的最大价值为0，
    cout << res << endl;
    
    return 0;        
}



// 题解大佬726写的dfs不错，但是会TLE，可参考

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 56;

int mp[maxn][maxn];
int vis[maxn][maxn];
int dir[2][2] = {{0, 1}, {1, 0}};

int n, m, k;
int max_item;
int ans;

bool check1(int x, int y) // 判断是否有越界
{
    if (x > 0 && x <= n && y > 0 && y <= m)
        return true;
    else
        return false;
}


void dfs(int x, int y, int cnt, int max_item)
{
    if (x == n && y == m) //到了终点要返回
    {
        if (cnt == k) // 到了终点的时候，手中有k件物品，答案就加一
            ans = (ans + 1) % 1000000007;
        return;
    }
    else
    {
        for (int i = 0; i < 2; i++) // 向下或者向右
        {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (!vis[dx][dy] && check1(dx, dy))
            {
                // 拿这件物品
                if (cnt != k && mp[dx][dy] > max_item)
                {
                    vis[dx][dy] = 1;
                    dfs(dx, dy, cnt + 1, mp[dx][dy]);
                    vis[dx][dy] = 0;
                }
                // 不拿这件物品
                vis[dx][dy] = 1;
                dfs(dx, dy, cnt, max_item);
                vis[dx][dy] = 0;
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }
    memset(vis, 0, sizeof(vis)); // 进去之后出来要刷新vis数组
    vis[1][1] = 1;
    dfs(1, 1, 1, mp[1][1]);
    vis[1][1] = 0;
    memset(vis, 0, sizeof(vis)); // 进去之后出来要刷新vis数组
    vis[1][1] = 1;
    dfs(1, 1, 0, -1);
    vis[1][1] = 0;
    memset(vis, 0, sizeof(vis)); // 进去之后出来要刷新vis数组
    cout << ans << endl;
}