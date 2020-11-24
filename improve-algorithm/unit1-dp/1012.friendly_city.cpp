#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5005;

int n;
PII q[N];
int f[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        q[i] = {a, b};
    }
    
    sort(q, q + n);
    
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = 0; j < i; ++j) 
            if (q[i].second > q[j].second)
                f[i] = max(f[i], f[j] + 1);
    }
    
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, f[i]);
    cout << res << endl;
    return 0;
    
}