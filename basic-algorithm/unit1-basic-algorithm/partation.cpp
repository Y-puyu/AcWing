#include <iostream>

using namespace std;

const int N = 1e5+5;

int n, k;
int q[N];

int partation(int q[], int l, int r, int k) {
    if (l == r) return q[l];    // 保证k一定在[l,r]区间
    int x = q[l+r>>1], i = l - 1, j = r + 1;
    while (i < j) {
        do ++ i; while (q[i] < x);
        do -- j; while (q[j] > x);
        if (i < j) swap (q[i], q[j]);
    }
    
    int sum = j - l + 1;
    if (sum >= k) return partation(q, l, j, k);
    return partation(q, j + 1, r, k - sum); 
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    
    cout << partation(q, 0, n - 1, k) << endl;
    
    return 0;
}