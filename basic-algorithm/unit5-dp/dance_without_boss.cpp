#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6005;

int n;
int happy[N];
int h[N*2], e[N*2], ne[N*2], idx;
int f[N][2];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++; 
}

void dfs(int u) {
    f[u][1] += happy[u];

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> happy[i];

    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1);

    cout << max(f[1][0], f[1][1]) << endl;

    return 0;
}