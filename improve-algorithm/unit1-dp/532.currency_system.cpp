#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105, M = 25005;

int n;
int a[N];
int f[M];

int main() {
    int T;
    cin >> T;
    
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        sort(a, a + n);
        
        memset(f, 0, sizeof f);
        
        f[0] = 1;
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!f[a[i]]) res ++;                       // f数组记录了所有能转移到的数的方案数
            for (int j = a[i]; j <= a[n - 1]; ++j)      // 在此背包容量为最大的那个数
                f[j] += f[j - a[i]];
        }
        cout << res << endl;
    }
    return 0;
}