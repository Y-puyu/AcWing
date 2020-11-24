#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;
int a[N];
int f[N], d[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for (int i = 0; i < n; ++i) {
        f[i] = d[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[i] > a[j]) 
                f[i] = max(f[i], f[j] + 1);
    }
    
    for (int i = n - 1; i >= 0; --i) {
        d[i] = 1;
        for (int j = n - 1; j >= i; --j) 
            if (a[i] > a[j])
                d[i] = max(d[i], d[j] + 1);
    }
    
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, f[i] + d[i] - 1);
    cout << res << endl;
    return 0;
}