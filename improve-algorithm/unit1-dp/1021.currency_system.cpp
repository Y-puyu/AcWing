#include <iostream>

using namespace std;

typedef long long LL;

const int N = 3005;

int n, m;
LL f[N];

int main() {
    cin >> n >> m;
    
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = a; j <= m; ++j) 
            f[j] += f[j - a];
    }
    
    cout << f[m] << endl;
    return 0;
}