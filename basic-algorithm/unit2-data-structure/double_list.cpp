// 主要做一些优化，暂未遇到

#include <iostream>
#include <string>

using namespace std;

const int N = 1e5+5;

int n;
int e[N], l[N], r[N], idx;

// 初始化
void init() {
    // 0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0, idx = 2;
}

// 在下标为k的点的右边，插入x
void add(int k ,int x) {
    e[idx] = x;
    l[idx] = k, r[idx] = r[k], l[r[k]] = idx, r[k] = idx, idx ++;   // 注意后两个的顺序
}

// 删除第k个点
void remove(int k) {
    l[r[k]] = l[k], r[l[k]] = r[k];
}

int main() {
    cin >> n;
    init();
    
    while (n --) {
        string op;
        cin >> op;
        int k, x;
        if (op == "L") {
            cin >> x;
            add(0, x);
        } else if (op == "R") {
            cin >> x;
            add(l[1], x);
        } else if (op == "D") {
            cin >> x;
            remove(x + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            add(l[k  + 1], x);
        } else {
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;
    
    return 0;
}