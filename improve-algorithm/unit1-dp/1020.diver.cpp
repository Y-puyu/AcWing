#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 25, M = 80;

int n, m, k;
int f[N][M];

int main() {
    cin >> n >> m >> k;
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    while (k --) {
        int a, b, w;
        cin >> a >> b >> w;
        for (int j = n; j >= 0; --j) 
            for (int k = m; k >= 0; --k)
                f[j][k] = min(f[j][k], f[max(0, j - a)][max(0, k - b)] + w);
    }
    cout << f[n][m] << endl;
    return 0;
}