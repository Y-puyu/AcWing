#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, MOD = 1e9+7;

int n;
int f[N];

int main() {
    cin >> n;
    
    f[0] = 1;
    
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            f[j] = (f[j] + f[j - i]) % MOD;
    
    cout << f[n] << endl;
    
    return 0;
}