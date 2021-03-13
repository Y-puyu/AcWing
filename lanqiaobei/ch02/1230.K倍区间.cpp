#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, k;
LL cnt[N], s[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    
    LL res = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        res += cnt[s[i] % k];
        cnt[s[i] % k] ++ ;
    }
    
    cout << res << endl;
    
    return 0;
}