#include <iostream>
#include <algorithm>
using namespace std;

int N = 1e5+10;
int n, a, b;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
        // cin>> a>>b;
        // cout << __gcd(a, b) << endl;
    }
    return 0;
}