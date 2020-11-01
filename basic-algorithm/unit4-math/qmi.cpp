#include <iostream>
using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p) {
    // 在此需要%p, 处理b=0,p=1的情况，课堂代码不够严谨，模板代码指出来该问题
    LL res = 1 % p;
    while (b) {
        if (b & 1) res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    return res; 
}

int main() {
    int n, a, b, p;
    scanf("%d", &n);
    while (n --) {
        scanf("%d%d%d", &a, &b, &p);
        cout << qmi(a, b, p) << endl;
    }
    return 0;
}