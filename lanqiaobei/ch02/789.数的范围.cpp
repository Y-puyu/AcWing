#include <iostream>

using namespace std;

const int N = 100005;

int n;
int a[N];

int main() {
    int T;
    cin >> n >> T;
    for (int i = 0; i < n; i ++ )  cin >> a[i];
    
    while (T -- ) {
        int k;
        cin >> k;
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] < k) l = mid + 1;
            else r = mid;
        }
        
        if (a[l] != k) cout << -1 << ' ' <<  -1 << endl;
        else {
            cout << l << ' ';
            l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (a[mid] > k) r = mid - 1;
                else l = mid;
            }
            cout << r << endl;
        }
    }
    return 0;
}