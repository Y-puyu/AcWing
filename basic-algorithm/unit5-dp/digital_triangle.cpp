#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int a[N][N];
int f[N][N];

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
    
    for (int i = n; i >= 1; --i)
        for (int j = i; j >= 1; --j)    
            f[i][j] = max(f[i + 1][j + 1], f[i + 1][j]) + a[i][j];
    
    cout << f[1][1] << endl;
    
    return 0;
}