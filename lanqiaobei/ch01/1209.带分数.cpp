// 纯暴力，近9000w计算量,3900ms
#include <iostream>

using namespace std;

const int N = 10;

int n;
int a[N];
int st[N];
int cnt;

int calc(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i ++ ) 
        res = res * 10 + a[i];
    return res;
}

void dfs(int u) {
    if (u == 9) {
        for (int i = 0; i < 9; i ++ ) 
            for (int j = i + 1; j < 9; j ++ ) {         // j 不能取等 9，若 j 取等 9 则，c b 均为 0，if 判断式子恒成立
                int a = calc(0, i);
                int b = calc(i + 1, j);
                int c = calc(j + 1, 8);
                if (n * c == a * c + b) cnt ++ ;
            }
        return ;
    }
    
    for (int i = 1; i <= 9; i ++ ) {
        if (!st[i]) {
            a[u] = i;
            st[i] = 1;
            dfs(u + 1);
            a[u] = 0;
            st[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << cnt << endl;
    return 0;
}


// 优化，1100ms
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 20;

int n;
bool st[N], backup[N];
int cnt;

bool check(int a, int c) {          // 动态计算b，并判断等式是否成立
    int b = n * c - a * c;
    
    if (!a || !b || !c) return false;
    
    memcpy(backup, st, sizeof st);  // backup需要改变，则 
    while (b) {                     // 拿到b的每一位
        int x = b % 10;
        b /= 10;
        if (!x || backup[x]) return false;     // 如果数位为0，或者其出现过，则错误
        backup[x] = true;           // 给这位打上标记
    }
    
    for (int i = 1; i <= 9; i ++ )
        if (!backup[i]) 
            return false;           // 如果1~9有数字没出现，则错误
    
    return true;
}

void dfs_c(int u, int a, int c) {   // a 已经确定，现在u及u后面的数字均为c，c一更新就动态计算 b，并对其进行判断
    if (u == n) return ;
    if (check(a, c)) cnt ++ ;
    
    for (int i = 1; i <= 9; i ++ ) 
        if (!st[i]) {
            st[i] = true;
            dfs_c(u + 1, a, c * 10 + i);
            st[i] = false;
        }
}

void dfs_a(int u, int a) {
    if (a >= n) return ;
    if (a) dfs_c(u, a, 0);  // a 不为 0 ，就找当前 a 下的所有的 c
    
    for (int i = 1; i <= 9; i ++ )      // 枚举当前第u位待填数字，全排列，按字典序枚举
        if (!st[i]) {                   
            st[i] = true;
            dfs_a(u + 1, a * 10 + i);   // 当前 i 被选择上了，更新 a
            st[i] = false;
        }
}

int main() {
    cin >> n;
    dfs_a(0, 0);      // 从第 0 位开始，选择后 a 的大小是多少，初始 a 未被选择，即为 0
    cout << cnt << endl;
    return 0;
}

// next_permutation， 3900ms
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9;

int n;
int a[N];

int cal(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i ++ ) 
        res = res * 10 + a[i];
    return res;
}

int main() {
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < 9; i ++ ) a[i] = i + 1;
    do {
        for (int i = 0; i < 7; i ++ ) 
            for (int j = i + 1; j < 8; j ++ ) {
                int a = cal(0, i);
                int b = cal(i + 1, j);
                int c = cal(j + 1, 8);
                if (n * c == a * c + b) cnt ++ ;
            }
    } while (next_permutation(a, a + 9));
    cout << cnt << endl;
    return 0;
}