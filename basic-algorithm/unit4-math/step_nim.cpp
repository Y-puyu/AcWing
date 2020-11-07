#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0, cnt = 0;
    while (n --) {
        int a;
        cin >> a;
        ++ cnt;
        if (cnt % 2) res ^= a;
    }
    puts(res ? "Yes": "No");
    return 0;
}