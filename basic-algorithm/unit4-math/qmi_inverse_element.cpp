#include <iostream>
using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main() {
    int n, a, p;
    cin >> n;
    while (n --) {
        scanf("%d%d", &a, &p);
        if (a % p == 0) puts("impossible");
        else cout << qmi(a, p - 2, p) << endl;
    }
    return 0;
}