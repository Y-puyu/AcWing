#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5005;

int n, m;
int s[N][N];

int main() {
    int T, r;
    cin >> T >> r;
    
    r = min(5001, r);
    
    n = m = r;          // 由于最后枚举的是左下角的点，当 r > n时 进不去循环，故至少 n = m = r，不影响前缀和
    // n = m = 5001  也可
    while (T -- ) {
        int x, y, w;
        cin >> x >> y >> w;
        x ++ , y ++ ;
        n = max(n, x), m = max(m, y);   // 上面写 n=m=5001就不用加这句，但是n=m=r的话，就导致当n>r或者m>r的时候代码就没进去枚举其他的子矩阵
        s[x][y] += w;
    }
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    
    int res = 0;
    for (int i = r; i <= n; i ++ )
        for (int j = r; j <= m; j ++ )
            res = max(res, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
    cout << res << endl;
    return 0;
}