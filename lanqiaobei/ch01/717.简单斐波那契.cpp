#include <iostream>

using namespace std;

const int N = 50;

int n;
int fib[N];


void init() {
    fib[0] = 0, fib[1] = 1, fib[2] = 1;
    for (int i = 3; i < N; i ++ ) fib[i] = fib[i - 1] + fib[i - 2];
}

int main() {
    cin >> n;
    init();
    for (int i = 0; i < n; i ++ ) cout << fib[i] << ' ';
    cout << endl;
    return 0;
}


// 简易滚动写法，滚动写法
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0, b = 1;
    for (int i = 1; i <= n; i ++ ) {
        cout << a << ' ';
        int c = a + b;
        a = b;
        b = c;
    }
    return 0;
}