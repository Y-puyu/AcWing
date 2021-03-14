#include <iostream>

using namespace std;

bool dfs(int m, int p, int q) {
    if (!m) return true;
    if (m >= p && dfs(m - p, p, q)) return true;
    if (m >= q && dfs(m - q, p, q)) return true;
    return false;
    
}


int main() {
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = 0; i < 1000; i ++ ) 
        if (!dfs(i, n, m))
            res = i;
    cout << res << endl;
    return 0;
}


// 公式法
#include <iostream>

using namespace std;

int main() {
    int p, q;
    cin >> p >> q;
    cout << (p - 1) * (q - 1) - 1 << endl;
    return 0;
}
