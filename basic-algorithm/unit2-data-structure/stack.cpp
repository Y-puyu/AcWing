#include <iostream>
#include <string>

using namespace std;

const int N = 1e5+5;

int m;
int stk[N], tt;

void push(int x) {
    stk[++tt] = x;  // 下标0空出来，作为判断栈空的标志
}

void pop() {
    --tt;
}

int top() {
    return stk[tt];
}

bool empty() {
    return tt <= 0;
}

int main() {
    cin >> m;
    while (m --) {
        string op;
        int x;
        cin >> op;
        if (op == "push") cin >> x, push(x);
        else if (op == "query") cout << top() << endl;
        else if (op == "empty") {
            if (empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else pop();
    }
    return 0;
}