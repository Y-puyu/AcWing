#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, m;
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int v, w;
        cin >> v >> w;
        for (int j = n; j >= v; --j)
            f[j] = max(f[j], f[j - v] + w);
    }
    
    cout << f[n] << endl;
    return 0;
}