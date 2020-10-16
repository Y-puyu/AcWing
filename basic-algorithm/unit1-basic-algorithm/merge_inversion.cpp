#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5+5;

int n;
int q[N], tmp[N];

LL merge_inversion(int q[], int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    // 可能会溢出，n-1+n-2+...+1 = n(n-1)/2,10^10
    LL res = merge_inversion(q, l, mid) + merge_inversion(q, mid + 1, r);
    
    // 归并
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else {
            tmp[k++] = q[j++];
            res += mid - i + 1; // 加上一句话，统计逆序对个数即可
        }
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    
    for (int i = l, j = 0; i <= r; ++i, ++j) q[i] = tmp[j];
    
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    cout << merge_inversion(q, 0, n - 1) << endl;
    return 0;
}