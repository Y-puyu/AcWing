#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MOD = 1e9+7;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % MOD;
        k >>= 1;
        a = (LL)a * a % MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int a = 2 * n, b = n;
    int res = 1;

    for (int i = a; i > a - b; --i) res = (LL)res * i % MOD;
    for (int i = 1; i <= b; ++i) res = (LL)res * qmi(i, MOD - 2, MOD) % MOD;

    res = (LL)res * qmi(n + 1, MOD - 2, MOD) % MOD;

    cout << res << endl;

    return 0;
}