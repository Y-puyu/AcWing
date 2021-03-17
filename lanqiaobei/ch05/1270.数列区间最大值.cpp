#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100005;

int n, m;
int w[N];
struct Node {
    int l, r;
    int maxv;
} tr[4 * N];

void pushup(int u) {
    tr[u].maxv = max(tr[u << 1].maxv, tr[u << 1 | 1].maxv);
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = { l, r, w[r] };
    else {
        tr[u] = { l, r };
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].maxv;
    
    int mid = tr[u].l + tr[u].r >> 1;           // 注意点
    int m = INT_MIN;
    if (l <= mid) m = max(m, query(u << 1, l, r));
    if (r >= mid + 1) m = max(m, query(u << 1 | 1, l ,r));          // 在这不写 +1 就被卡死了
    
    return m;
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);      // 1e6 级别，需要使用 cstdio
    
    build(1, 1, n);
    
    int x, y;
    while (m -- ) {
        scanf("%d%d", &x, &y);
        printf("%d\n", query(1, x, y));
    }
    
    return 0;
}