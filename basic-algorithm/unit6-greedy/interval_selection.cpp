#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;

struct Range {
    int l, r;
    bool operator<(const Range &W) const {
        return r < W.r;
    }
}range[N];

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    int res = 0, ed = -2e9;
    for (int i = 0; i < n; ++i) 
        if (ed < range[i].l)
            ++res, ed = range[i].r;
    
    cout << res << endl;
    
    return 0;
}