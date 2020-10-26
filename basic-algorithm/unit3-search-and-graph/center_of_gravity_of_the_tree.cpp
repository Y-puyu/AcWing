#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+5;

int n;
int h[N], e[N * 2], ne[N * 2], idx; // 邻接表
bool st[N];     // 判断节点是否已经被访问过了

int ans = N;    // 最终结果，需要和每个节点返回的max取min

void add(int a, int b) {    // 在邻接表中加上一条a->b的单向边
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

// 暴力枚举，深搜，找到树中每个节点的重心连通块最大值，每次取个min即可
// 返回以u为根的子树中点的数量
int dfs(int u) {
    st[u] = true;   // u已经被访问过了

    // sum表示当前子树的大小包括重心，所以初始化为1
    // res表示删除当前节点后连通块的最大值
    int sum = 1, res = 0;   
    for (int i = h[u]; i != -1; i = ne[i]) {    // 遍历它的出边所有节点，选出最大的连通块res
        int j = e[i];       // 链表节点对应到图中节点的编号
        if (!st[j]) {       // 未被遍历过，则说明它和它的子树都未被遍历过
            int s = dfs(j); // 递归得到节点j为根的子树各个连通块节点的数量
            res = max(res, s);  // 取max得到这条链上所有连通块的最大值
            sum += s;           // 加上s是对所有连通块求和，得到这个子树的所有节点数
        }
    }

    res = max(res, n - sum);    // 和重心父节点所在的连通块去max

    ans = min(ans, res);        // 至此，根节点的重心最大连通块数量已经求出,即res,每次res取min即可

    return sum;
}

int main() {
    memset(h, -1 ,sizeof h);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}