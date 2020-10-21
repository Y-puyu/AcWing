// 主要用来模拟邻接表

#include <iostream>

using namespace std;

const int N = 1e5+5;

int n;
int head, e[N], ne[N], idx;

void init() {
    head = -1, idx = 0;
}

void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx, ++idx;
}

void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx, ++idx;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    cin >> n;
    
    init();
    
    while (n --) {
        int k, x;
        char op;
        
        cin >> op;
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            cin >> k;                   
            if (!k) head = ne[head];    // 如果是k=0,则意味着删除头结点,特判一下
            remove(k - 1);              // 下标从0开始，则第k个插入的点的下标应该是k-1
        } else {
            cin >> k >> x;
            add(k - 1, x);              // 注意下标是操作数减1
        }
    }
    
    for (int i = head; i != - 1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    
    return 0;
}