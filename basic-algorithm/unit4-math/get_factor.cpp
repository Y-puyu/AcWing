#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a;

vector<int> get_divitors(int n) {
    vector<int> vt;
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            vt.push_back(i);
            if (n / i != i) vt.push_back(n / i);
        }
    }
    sort(vt.begin(), vt.end());
    return vt;
}

int main() {
    scanf("%d", &n);
    while (n --) {
        scanf("%d", &a);
        auto vt = get_divitors(a);
        for (auto e:vt) cout << e << ' ';
        cout << endl;
    }
    return 0;
}