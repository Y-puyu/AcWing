#include <iostream>

using namespace std;

const int N = 10005;

int n;
int a[N];

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        int mx = -1, mi = 10005;
        for (int j = i; j <= n; j ++ ) {
            mx = max(mx, a[j]);
            mi = min(mi, a[j]);
            if (mx - mi == j - i) res ++ ;
        }
    }
    cout << res << endl;
    return 0;
}