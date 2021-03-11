// 顺序枚举当前位置应该填什么数字
#include <iostream>

using namespace std;

const int N = 10;

int n;
int a[N];       // 0 表示未填充，1~n 表示当前位置填充的数字
bool st[N];     // true 表示当前数字已经填充使用过了，false 表示未使用当前数字

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; i ++ )
            cout << a[i] << ' ';
        cout << endl;
        return ;
    }
    
    for (int i = 1; i <= n; i ++ ) {    // 顺序枚举这 n 个数，即是按字典序进行枚举填充
        if (!st[i]) {
            a[u] = i;
            st[i] = true;
            dfs(u + 1);
            a[u] = 0;
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}

// 顺序枚举数字应该填充到哪个位置，可以枚举所有结果，但是无法保证字典序
// 假设 1 被枚举到第二、第三等位置上，那么很容易 5 就被枚举到第一的位置上并且被输出
#include <iostream>

using namespace std;

const int N = 10;

int n;
int a[N];       // 0 表示未填充，1~n 表示当前位置填充的数字

void dfs(int u) {   // 待填充的数
    if (u > n) {
        for (int i = 1; i <= n; i ++ )
            cout << a[i] << ' ';
        cout << endl;
        return ;
    }
    
    for (int i = 1; i <= n; i ++ ) {    // 枚举 n 个位置，无法保证字典序
        if (!a[i]) {
            a[i] = u;
            dfs(u + 1);
            a[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}

// STL next_permutation
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++ ) a[i] = i + 1;
    do {
        for (int i = 0; i < n; i ++ ) cout << a[i] << ' ';
        cout << endl;
    } while (next_permutation(a, a + n));
    return 0;
}