#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5+5;

int n, m;
int e[N*2], ne[N*2], h[N], idx;
int st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool bfs(int u) {               // 相当于染一个连通块
    int hh = 0, tt = 0;
    PII q[N];                   // 定义队列，<点编号，颜色>
    q[0] = {u, 1};
    st[u] = 1;

    while (hh <= tt) {          // 队列不空
        auto t = q[hh ++];
        int ver = t.first, c = t.second;

        for (int i = h[ver]; i != -1; i = ne[i]) {      // 遍历队头临边，染色
            int j = e[i];

            if (!st[j]) {
                st[j] = 3 - c;
                q[++ tt] = {j, 3 - c};
            }
            else if (st[j] == c) return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);

    while (m --) {
        int a, b;
        cin >> a >> b;

        add(a, b), add(b, a);       // 无向图
    }

    int flag = true;
    for (int i = 1; i <= n; ++i) {      // 遍历所有点，防止不连通
        if (!st[i]) {
            if (!bfs(i)) {
                flag = false;
                break;
            }
        }
    }

    if (bfs(1)) puts("Yes");
    else puts("No");

    return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+5;

int n, m;
int h[N], ne[N*2], e[N*2], idx;     // 无向图存边数量是两倍
int color[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!color[j]) {
            if (!dfs(j, 3 - c)) return false;
        } 
        else if (color[j] == c) return false;
    }
    return true;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    
    while (m --) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {            // 如果当前点未被染色
            if (!dfs(i, 2)) {       // dfs返回false则染色出现问题，在此初始颜色随便定义
                flag = false;
                break;
            }
        }
    }
    
    if (flag) puts("Yes");
    else puts("No");
    
    return 0;
}