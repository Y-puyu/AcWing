#include <iostream>
using namespace std;

void get_euler(int a) {
    int res = a;
    for (int i = 2; i <= a / i; ++i) {
        if (a % i == 0) {
            res  = res / i * (i - 1);
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) res = res / a * (a - 1);
    cout << res << endl;
}

int main() {
    int n, a;
    cin >> n;
    while (n --) {
        cin >> a;
        get_euler(a);
    }
    return 0;
}