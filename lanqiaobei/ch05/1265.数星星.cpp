#include <iostream>

using namespace std;

const int N = 32005;

int n;
int tr[N], level[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i < N; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int x, y;
        cin >> x >> y;
        x ++ ;
        
        level[query(x)] ++ ;
        add(x, 1);
    }
    
    for (int i = 0; i < n; i ++ ) cout << level[i] << endl;
    
    return 0;
}