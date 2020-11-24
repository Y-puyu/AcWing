#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6005;

int n, m;
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= v; --j)
            for (int k = 0; k * v <= j && k <= s; ++k)
                f[j] = max(f[j], f[j - k * v] + k * w);
    }
    cout << f[m] << endl;
    return 0;
}