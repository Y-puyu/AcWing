#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 55, MOD = 1e9+7;

int n;
char str[N];
int f[N][N];
int ne[N];

int main() {
    cin >> n >> str + 1;
    
    int len = strlen(str + 1);
    
    // 求next数组
    for (int i = 2, j = 0; i <= len; ++i) {
        while (j && str[i] != str[j + 1]) j = ne[j];
        if (str[i] == str[j + 1]) j ++;
        ne[i] = j;
    }
    
    f[0][0] = 1;            // 状态初始化,一个字母都没有,也是一种方案
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < len; ++j)               // 枚举j的位置,不包括子串的末尾len
            for (char k = 'a'; k <= 'z'; ++k) {     // i的26种选法,也可视为状态j的26种出边
                int u = j;
                // s[i]失配跳ne,得到最后的kmp位置,在这不论是单个字母还是字符串,kmp都是while,
                // 在此是一个字母就只判断一次,最终停下来u大多都是0吧
                while (u && k != str[u + 1]) u = ne[u];    
                if (k == str[u + 1]) u ++;
                if (u < len) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % MOD;   // 采用后继更新前驱节点
            }
    
    int res = 0;
    for (int i = 0; i < len; ++i) res = (res + f[n][i]) % MOD;
    cout << res << endl;
    
    return 0;
}