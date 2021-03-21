#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100005;

int T;
int head, e[N], ne[N], idx;

void add_to_head(int a) {
    e[idx] = a, ne[idx] = head , head = idx ++;
}

void del(int a) {
    ne[a] = ne[ne[a]];
}

void insert(int a, int b) {
    e[idx] = b;
    ne[idx] = ne[a];
    ne[a] = idx ++ ;
}

int main() {
    head = -1, idx = 1;
    
    cin >> T;
    while (T -- ) {
        char op;
        int a, b;
        cin >> op;
        if (op == 'H') cin >> a, add_to_head(a);
        else if (op == 'I') cin >> a >> b, insert(a, b);
        else {
            cin >> a;
            if (!a) head = ne[head];
            del(a);
        }
    }
    
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    
    return 0;
}