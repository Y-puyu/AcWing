#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5005;

int primes[N], cnt;
int sum[N];
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; ++j) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

// 直观，有溢出风险
int get(int n, int p) {
    int res = 0,t = p;
    while (n >= p) {
        res += n / p;
        p *= t;
    }
    return res;
}

// 精炼简介，完美版本
int get1(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> a, int b) {
    vector<int> C;
    int t = 0;

    for (int i = 0; i < a.size(); ++i) {
        t += a[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (t) {
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

int main() {
    int a, b;
    cin >> a >> b;

    get_primes(a);

    for (int i = 0; i < cnt; ++i) {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; ++i) 
        for (int j = 0; j < sum[i]; ++j)
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; --i) cout << res[i];
    cout << endl;

    return 0;
}