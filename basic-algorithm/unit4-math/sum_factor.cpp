#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

int main() {
    int n, a;
    cin >> n;
    unordered_map<int, int> primes;
    while (n --) {
        cin >> a;
        for (int i = 2; i <= a / i; ++i) {
            while (a % i == 0) {
                a /= i;
                primes[i] ++;
            }
        }
        if (a > 1) primes[a] ++;
    }

    LL res = 1;
    for (auto e:primes) {
        LL a = e.first, b = e.second, t = 1;
        while (b --) t = (t * a + 1) % MOD;
        res = res * t % MOD;
    }
    cout << res << endl;
    return 0;
}