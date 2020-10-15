#include <iostream>

using namespace std;

const double eps = 1e-8;

double n;

int main() {
    scanf("%lf", &n);   
    int flag = 1;
    if (n < 0) n = -n, flag = -1;
    double l = 0, r = n;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6lf", l * flag);
    return 0;
}