#include <iostream>
using namespace std;

void divide(int n) {
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (n > 1) printf("%d %d\n", n, 1);
}

int main() {
    int n, a;
    scanf("%d", &n);
    while (n --) {
        scanf("%d", &a);
        divide(a);
        puts("");
    }
    return 0;
}