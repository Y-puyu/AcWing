#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;
const int MOD = 1e9+7;

int main() {
    int n, a;
    scanf("%d", &n);

    unordered_map<int, int> primes;
    while (n --) {
        scanf("%d", &a);
        for (int i = 2; i <= a / i; ++i) {
            while (a % i == 0) {
                a /= i;
                primes[i] ++;
            }
        }
        if (a > 1) primes[a] ++;
    }
    LL res = 1;
    for (auto e:primes) res = res * (e.second + 1) % MOD;
    cout << res << endl;
    return 0;
}