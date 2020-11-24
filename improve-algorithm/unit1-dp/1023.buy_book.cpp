#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;
int m[5] = {0, 10, 20, 50, 100};
int f[5][N];

int main() {
    cin >> n;
    f[0][0] = 1;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 0; j <= n; j ++) {
            f[i][j] = f[i - 1][j];
            if (j >= m[i]) f[i][j] += f[i][j - m[i]];
        }
    }
    cout << f[4][n] << endl;
    return 0;
}