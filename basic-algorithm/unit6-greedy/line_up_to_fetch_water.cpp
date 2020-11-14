#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    sort(a, a + n);
    
    long long res = 0;      // WA后就知道开long long 了...
    
    for (int i = 0; i < n; ++i) res += a[i] * (n - i - 1);
    cout << res << endl;
    
    return 0;
}