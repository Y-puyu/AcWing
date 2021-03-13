#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int s[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        int a;
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}