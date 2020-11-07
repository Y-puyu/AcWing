#include <iostream>

using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    while (n --) {
        int a;
        cin >> a;
        res ^= a;
    }
    if (res) puts("Yes");
    else puts("No");
    return 0;
}