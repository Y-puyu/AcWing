#include <iostream>

using namespace std;

const int N = 1e5+5;

int son[N][26], cnt[N], idx;

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
        
    }
    return cnt[p];
}

int main() {
    int m;
    cin >> m;
    
    while (m --) {
        char op[2], str[N];
        cin >> op >> str;
        if (op[0] == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}