#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10005;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    int res = 0;
    for (int i = 1; i <= n; i ++ )                  // 每次归位一个不在位置上的 i
        for (int j = 0; j < n; j ++ ) {
            if (a[j] == i && j != i - 1) {          // 当位置不符时，再进行交换
                swap(a[i - 1], a[j]);
                res ++ ;
                break;
            }
        }

    cout << res << endl;
    
    return 0;
}


// 当 n 个点构成 n 个环，则必然是 n 个自环
// 在本题规则下，必然是各自在位置上的自环
// 特点：
// 1. 节点大于等于 2 的环必然可以交换环中节点，使得环一分为二
// 2. 两个不同的环中的节点交换，等价于两个环合并。    但在本问题中，环应该不会合并
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 10005;

int n;
int a[N];
bool st[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    int k = 0;
    for (int i = 1; i <= n; i ++ ) {    // 顺序枚举 1~n
         if (!st[i]) {                  // 如果这个数 i 没被遍历过，说明它是一个新环节点
             k ++ ;
             for (int j = i; !st[j]; j = a[j])  // 将 i 所在环中的所有节点加入
                st[j] = true;
         }
    }
    
    cout << n - k << endl;
    
    return 0;
}