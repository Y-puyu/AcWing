#include <iostream>

using namespace std; 

typedef long long LL;

const int N = 100005;

int n;
int a[N], temp[N];

LL merge(int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    LL cnt = merge(l, mid) + merge(mid + 1, r);   // 逆序对被分为三种情况，双左，双右，递归就求出来了，在归并过程中求出单左单右的情况即可
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k ++ ] = a[i ++ ];
        else temp[k ++ ] = a[j ++ ], cnt += mid - i + 1;
    }
    while (i <= mid) temp[k ++ ] = a[i ++ ];
    while (j <= r) temp[k ++ ] = a[j ++ ];
    
    for (int i = l, j = 0; i <= r; i ++ , j ++ ) a[i] = temp[j];
    
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    cout << merge(0, n - 1) << endl;
    
    return 0;
}