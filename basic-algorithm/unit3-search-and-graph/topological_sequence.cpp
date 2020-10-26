#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+5;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort() {
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; ++i)    // 入队入度为0的点
        if (!d[i])
            q[++ tt] = i;

    while (hh <= tt) {
        int t = q[hh ++];   // 仅移动指针，并未真的删除，里面存的就是拓扑序列

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j] --;        // j入度减1，相当于删去了这条边
            if (d[j] == 0) q[++ tt] = j;
        }
    }
    return tt == n - 1;     // 如果tt为n-1说明所有的点都已经进过队列了，说明它是个有向无环图    
}


int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++;
    }

    if (topsort()) {
        for(int i = 0; i < n; ++i) cout << q[i] << ' ';
        puts("");
    } 
    else {
        cout << -1 << endl;
    }
    return 0;
}