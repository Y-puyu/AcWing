#include <iostream>

using namespace std;

const int N = 1e5+5, M = 4e6;

int n;
int a[N], son[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if (son[p][!u]) {
            p = son[p][!u];
            res = res * 2 + !u;
        } else {
            p = son[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = 0;
    for (int i = 0; i < n; ++i) {
        insert(a[i]);
        int t = query(a[i]);
        res = max(res, a[i] ^ t);
    }
    cout << res << endl;
    return 0;
}