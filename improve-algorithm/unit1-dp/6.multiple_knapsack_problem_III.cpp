#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e4+5;

int n, m;
int f[N], g[N], q[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);                 
        for (int j = 0; j < v; ++j) {           
            int hh = 0, tt = -1;                
            for (int k = 0; k <= (m - j) / v; k ++) {       // 枚举个数
                if (hh <= tt && k - q[hh] > s) hh ++;   
                while (hh <= tt && g[q[tt] * v + j] - q[tt] * w <= g[k * v + j] - k * w)  tt --;
                q[++tt] = k;  
                f[k * v + j] = max(f[k * v + j], g[q[hh] * v + j] + (k - q[hh]) * w);     
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}