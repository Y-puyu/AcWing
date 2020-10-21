#include <iostream>

using namespace std;

const int N = 1e5+5, M = 1e6+5;

int n, m;
char s[N], p[M];
int ne[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;
    
    // 求ne数组过程，其实就是自己匹配自己的过程
    for (int i = 2, j = 0; i <= n; ++i) {       // ne[1]为0，即如果第一个字母失败了，则只能从头开始了
        while (j && p[i] != p[j + 1]) j = ne[j];    // 未匹配，跳ne
        if (p[i] == p[j + 1]) j ++;     // 匹配成功看下一位
        ne[i] = j;      // 表示下标以i-j为起点，i为终点的后缀和下标以0为起点，j为终点的前缀相等
    }
    
    // kmp匹配过程，每次是p[j+1]与s[i]进行匹配
    for (int i = 1, j = 0; i<= m; ++i) {
        while (j && s[i] != p[j + 1]) j = ne[j];    // j没有退回起点，失配跳ne[j]
        if (s[i] == p[j + 1]) ++j;      // 可以匹配，则j后移一位
        if (j == n) {                   // 匹配成功，长度就是m
            cout << i - n << ' ';
            // 匹配成功，即j已经走到了头，下一次匹配的时候，j往后移动的位置就是，j=ne[j]更新下j的位置就行了
            j = ne[j];  
        }
    }
    return 0;
}