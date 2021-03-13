#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

bool check(int u) {
    for (int i = 0; i < n; i ++ ) {
        u = u * 2 - a[i];
        if (u > 1e5) return true;
        if (u < 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ )  cin >> a[i];
    
    int maxh = 0;
    for (int i = 0; i < n; i ++ ) maxh = max(maxh, a[i]);
    
    int l = 0, r = maxh;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
    
}