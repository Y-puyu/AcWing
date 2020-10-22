#include <iostream>

using namespace std;

const int N = 1e5+5;

int n, m;
int p[N];  // 存储每个元素的父节点是谁，初始化时每个元素单独一个集合，即为自己,p[x]=x

// 返回x的祖宗节点+路径压缩
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);  // 如果p[x]不是树根节点，则让p[x]等于它的树根节点
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) p[i] = i;  // 初始化，每个元素单独一个集合，为树根
    
    while (m --) {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        if (op[0] == 'M') p[find(a)] = find(b); 
        else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}