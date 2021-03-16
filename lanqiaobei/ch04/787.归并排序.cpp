#include <iostream>

using namespace std;

const int N = 100005;

int n;
int a[N], temp[N];

void merge(int l, int r) {
    if (l >= r) return ;
    int mid = l + r >> 1;
    merge(l, mid), merge(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) temp[k ++ ] = a[i ++ ];
        else temp[k ++ ] = a[j ++ ];
    }
    while (i <= mid) temp[k ++ ] = a[i ++ ];
    while (j <= r) temp[k ++ ] = a[j ++ ];
    
    for (int i = l, j = 0; i <= r; i ++ , j ++ ) a[i] = temp[j];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    merge(0, n - 1);
    
    for (int i = 0; i < n; i ++ ) cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}