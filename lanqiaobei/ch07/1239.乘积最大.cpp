// 很困难的一道问题，分5种情况讨论，最后将问题进行统一的转化处理
// 情况很多，但是找到共性之后就变得统一起来了
// 很不错的一道题

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 5, MOD = 1000000009;

int n, k;
LL a[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++ )  cin >> a[i];
    
    sort(a, a + n);
    
    LL res = 1, l = 0, r = n - 1, sign = 1;
    if (k >= n) {                           // 第一类大情况，选择所有数
        for (int i = 0; i < n; i ++ ) res = res % MOD * a[i] % MOD;
    } else{
        if (k % 2) {            // k为奇数时，特判第三种情况。其结果必然为负数，要保证负数尽量大，其余各情况可整体拿双指针进行操作，首尾选一对
            res = a[r -- ];     // 选择最右端的负数。然后 k-1 为偶数，然后首尾选一对的过程中需要乘上符号特判这个全负数的情况
            k -- ;              // 其中首尾选一对过程中都是正数，但需要保证乘积小，需要乘上这个符号
            if (res < 0) sign = -1;         // 特判当 k 为奇数且所有数均为负数的情况，此时结果只会是负数
        }
        while (k) {
            LL x = a[l] * a[l + 1], y = a[r] * a[r - 1];    // 每次选一对
            if (x * sign > y * sign) res = x % MOD * res % MOD, l += 2;     // 每次需要特判第三种情况，如果符号为1，则选大的，符号为-1，选小的
            else res = y % MOD * res % MOD, r -= 2;
            
            k -= 2;
        }
        
    }
    cout << res << endl;
    
    return 0;
}