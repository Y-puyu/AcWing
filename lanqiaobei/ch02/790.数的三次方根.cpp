#include <iostream>

using namespace std;

int main() {
    double n;
    cin >> n;
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double mid = (l + r)  / 2;
        if (mid * mid * mid < n) l = mid;
        else r = mid;
    }
    printf("%.6f\n", l);        // printf("%lf", l)  默认保留六位小数
    return 0;
}