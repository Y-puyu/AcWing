// 注意负数取模问题，将其映射为正数，数组下标为负，程序会WA...但并不严格报错

#include <iostream>

using namespace std;

const int N = 1005, MOD = 100000007;

int n, s, a, b;
int f[N][N];

int get_mod(int a, int b) {
    return ((a % b) + b) % b;
}

int main() {
    cin >> n >> s >> a >> b;
    
    f[0][0] = 1;
    
    for (int i = 1; i < n; i ++ )               // 只枚举 n-1 项
        for (int j = 0; j < n; j ++ ) {
            f[i][j] = (f[i - 1][get_mod(j - i * a, n)] + f[i - 1][get_mod(j + i * b, n)]) % MOD;
        }

    cout << f[n - 1][get_mod(s, n)] << endl;
    
    return 0;
}