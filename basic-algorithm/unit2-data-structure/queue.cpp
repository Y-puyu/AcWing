#include <iostream>

using namespace std;

const int N = 1e5+5;

int m;
int q[N], hh, tt = -1;

void push(int x) {
    q[++tt] = x;
}

void pop() {
    ++hh;
}

int front() {
    return q[hh];
}

bool empty() {
    return hh > tt;
}

int main() {
    cin >> m;
    while (m --) {
        string op;
        int x;
        cin >> op;
        if (op == "push") cin >> x, push(x);
        else if (op == "query") cout << front() << endl;
        else if (op == "empty") {
            if (empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else pop();
    }
    return 0;
}