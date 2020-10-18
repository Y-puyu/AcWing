#include <iostream>

using namespace std;

const int N = 100010;
int a[N], b[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) b[i] = a[i] - a[i - 1];
    
    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        b[l] += c;
        b[r + 1] -= c;
    }
    
    for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
    
    for (int i = 1; i <= n; ++i) cout << b[i] << " ";
    return 0;
}