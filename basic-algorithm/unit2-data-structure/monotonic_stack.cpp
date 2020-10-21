#include <iostream>

using namespace std;

const int N = 1e5+5;

int n;
int stk[N], tt;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt--;
        if (tt) cout << stk[tt] << ' ';
        else cout << -1 << ' ';
        stk[++tt] = x;
    }
    return 0;
}