#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005, V = 105, M = 105;

int n, v, m;
int f[V][M];

int main() {
    cin >> n >> v >> m;
    for (int i = 0; i < n; ++i) {
        int vi, mi, wi;
        cin >> vi >> mi >> wi;
        for (int j = v; j >= vi; --j) {
            for (int k = m; k >= mi; --k)
                f[j][k] = max(f[j][k], f[j - vi][k - mi] + wi);
        }
    }
    cout << f[v][m] << endl;
    return 0;
}