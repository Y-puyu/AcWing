#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, m;
int v[N], w[N];
int f[N][N], g[N][N];

// 递归打印，参考:https://www.acwing.com/solution/content/19760/
void print(int x,int y)
{
    if(x == n + 1) return;
    int k = g[x][y];
    //判断是否选择了第x件物品
    if(k) cout<<k<<' ';//在递归函数的上面为由根节点到叶子节点进行操作
    print(x+1,y-v[k]);
    //在递归函数的下面进行操作，为叶子节点遍历完了，回溯由子节点到根节点进行操作

}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    
    for (int i = n; i >= 1; i --) 
        for (int j = 0; j <= m; j ++) {
            f[i][j] = f[i + 1][j];
            if (j >= v[i]) {
                if (f[i][j] <= f[i + 1][j - v[i]] + w[i]) { 
                    f[i][j] = max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]);
                    g[i][j] = i;
                }
            }
        }
    
    // 递归
    print(1, m);
    
    // 非递归
    int j = m;
    for (int i = 1; i <= n; ++i) {
        if (j >= v[i]) {
            if (g[i][j]) {
                cout << g[i][j] << ' ';
                j -= v[i];
            }
        }
    }

    return 0;
}