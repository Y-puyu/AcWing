#include <iostream>

using namespace std;

const int N = 1e5+5;

int n, m;
int p[N], s[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) p[i] = i, s[i] = 1;
    
    while (m --) {
        char op[2];
        int a, b;
        cin >> op;
        if (op[0] == 'C') {
            cin >> a >> b;
            // 如果a,b在同一个集合里，则直接continue，不用再累加集合元素了
            if (find(a) == find(b)) continue;   
            s[find(b)] += s[find(a)];
            p[find(a)] = find(b);
        } else if (op[1] == '1') {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        } else {
            cin >> a;
            cout << s[find(a)] << endl;
            
        }
    }
}