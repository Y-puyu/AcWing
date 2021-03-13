#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, k;
int w[N], h[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> w[i] >> h[i];
    
    int l = 1, r = N;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        int cnt = 0;
        for (int i = 1; i <= n; i ++ )
            cnt += (w[i] / mid) * (h[i] / mid);
        if (cnt < k) r = mid - 1;
        else l = mid;
    }
    cout << l << endl;
    return 0;
}