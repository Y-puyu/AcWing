#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 5;

int n;
int w[N], tr[N];
int sum[N];

int lowbit(int x) { return x & -x; }

void add(int x, int v) {
    for (int i = x; i < N; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    
    // 树状数组维护 w[i] 前面有多少数字比他大
    for (int i = 1; i <= n; i ++ ) {
        sum[i] = query(N - 1) - query(w[i]);
        add(w[i], 1);
    }
    
    memset(tr, 0, sizeof tr);
    
    for (int i = n; i >= 1; i -- ) {
        sum[i] += query(w[i] - 1);
        add(w[i], 1);
    }
    
    LL res = 0;
    for (int i = 1; i <= n; i ++ ) res += (LL)sum[i] * (sum[i] + 1) / 2;
    cout << res << endl;
    
    return 0;
}