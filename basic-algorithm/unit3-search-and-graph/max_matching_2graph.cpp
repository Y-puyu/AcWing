#include <iostream>
#include <cstring>

using namespace std;

const int N = 505, M = 1e5+5;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];           // 妹子牵手的男生
bool st[N];             // 判重不要重复搜一个点

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

// 将男生x加入，如果x来加入匹配，是否能让匹配数增多
bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {    // 遍历自己的妹子
        int j = e[i];                           // j为妹子编号
        if (!st[j]) {                           // 如果妹子j还没匹配
            st[j] = true;                       // x预定j成功，调整时前男友就别看了
            if (match[j] == 0 || find(match[j])) { // 如果j没男友,或者可以给那个男生找到备胎，则匹配成功
                match[j] = x;                      // 即便匹配失败，也不更改结果，匹配总数不减小
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);

    while (m --) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;                        // 当前匹配数量
    for (int i = 0; i <= n1; ++i) {     // 分析下每个男生应该找哪个妹子
        memset(st, false, sizeof st);   // 每次的预定情况都不一样，所有每轮都清空，保证在递归过程中每个女生只能被选一次
        if (find(i)) res ++;
    }
    cout << res << endl;
    return 0;
}