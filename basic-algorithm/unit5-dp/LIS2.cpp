#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;

int n;
int a[N];
int q[N];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int cnt = 0;
    q[0] = -2e9;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = cnt;
        while (l < r) {
            int mid = l + r + 1>> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        cnt = max(cnt, r + 1);
        q[r + 1] = a[i];
    }
    cout << cnt << endl;
    return 0;
}