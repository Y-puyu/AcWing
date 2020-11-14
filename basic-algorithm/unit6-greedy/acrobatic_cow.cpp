#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5e5+5;

int n;
PII cow[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int w, s;
        cin >> w >> s;
        cow[i] = {w + s, s};
    }
    
    sort(cow, cow + n);
    
    int res = -2e9, sum = 0;
    for (int i = 0; i < n; ++i) {
        int w = cow[i].first - cow[i].second, s = cow[i].second; 
        res = max(res, sum - s);
        sum += w;
    }
    
    cout << res << endl;
    return 0;
}