#include <iostream>
#include <cmath>

using namespace std;

const int N = 105;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; ++c) {    // c列r行，遍历列
        int t = r;

        for (int i = r; i < n; ++i)     // 寻找列主元，拿t记录
            if (fabs(a[i][c]) > fabs(a[t][c])) 
                t = i;              

        if (fabs(a[t][c]) < eps) continue;  // 如果列主元为0，不必考虑，当前列全为0

        // 交换列主元t行与当前r行的数
        for (int i = c; i < n + 1; ++i) swap(a[t][i], a[r][i]); 
        // 当前列主元已经被交换到了r行，需要从后向前进行处理，避免主对角线元素变成1
        for (int i = n; i >= c; --i) a[r][i] /= a[r][c]; 

        // 列主消元
        for (int i = r + 1; i < n; ++i) 
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; --j) 
                    a[i][j] -= a[r][j] * a[i][c];

        ++r;
    }

    if (r < n) {
        for (int i = r; i < n; ++i) 
            if (fabs(a[i][n]) > eps) return 2;  // 0x=1 则无解

        return 1;   // 0x=0 无穷多解
    }

    // 上三角阶梯型矩阵
    // 直接求解即可，最后一列放置结果
    for (int i = n - 1; i >= 0; --i)    
        for (int j = i + 1; j < n; ++j) 
            a[i][n] -= a[j][n] * a[i][j];

    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n + 1; ++j) 
            cin >> a[i][j];

    int t = gauss();

    if (t == 0) {
        for (int i = 0; i < n; ++i) printf("%.2lf\n", a[i][n]);
    } 
    else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");

    return 0;
}