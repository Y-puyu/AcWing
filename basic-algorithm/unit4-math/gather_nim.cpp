#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 105, M = 1e4+5;

int n, k;
int s[N], f[M];     // s存取石子的方法，f存取所有取法对应的sg值

// dfs求取sg结果
int sg(int x) {
    if (f[x] != -1) return f[x];

    unordered_set<int> S;               // 哈希表存所有可以到的局面
    for (int i = 0; i < k; ++i) 
        if (x >= s[i]) 
            S.insert(sg(x - s[i]));     

    for (int i = 0 ; ; ++i) 
        if (!S.count(i))
            return f[x] = i;
}

int main() {
    cin >> k;                   // s个固定取法

    memset(f, -1, sizeof f);    // 记忆化搜索数组初始化

    for (int i = 0; i < k; ++i) cin >> s[i];    

    cin >> n;                   // 每堆石子的数量

    int res = 0;            
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    puts(res ? "Yes" : "No");
    return 0;
}