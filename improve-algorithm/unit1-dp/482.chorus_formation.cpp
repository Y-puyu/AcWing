#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3+5;

int n;
int a[N];
int f[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for (int i = 0; i < n; ++i) {
        f[i] = a[i];
        for (int j = 0; j < i; ++j)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + a[i]);
    }
    
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}