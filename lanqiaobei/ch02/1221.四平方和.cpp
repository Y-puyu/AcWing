// 注意下枚举的顺序，是如何保证  a b c d 是字典序输出的，很巧妙


#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 2500005;

struct Sum {
    int s, c, d;
    bool operator< (const Sum S) {
        if (s != S.s) return s < S.s;
        if (c != S.c) return c < S.c;
        return d < S.d;
    }
}sum[N];


int n, m;

int main() {
    cin >> n;
    
    for (int c = 0; c * c <= n; c ++ ) 
        for (int d = c; c * c + d * d <= n; d ++ ) 
            sum[m ++ ] = {c * c + d * d, c, d};
    
    sort(sum, sum + m);
    
    for (int a = 0; a * a <= n; a ++ ) 
        for (int b = a; a * a + b * b <= n; b ++ ) {
            int t = n - a * a - b * b;
            int l = 0, r = m - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (sum[mid].s >= t) r = mid;
                else l = mid + 1;
            }
            if (sum[l].s == t) {
                cout << a << ' ' << b << ' ' << sum[l].c << ' ' << sum[l].d << endl;
                return 0;
            }
        }
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <algorithm>

#pragma GCC optimize(2)

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int main() {
    int n;
    cin >> n;
    unordered_map<int, PII> S;
    for (int a = 0; a * a <= n; a ++ )
        for (int b = a; b * b + a * a <= n; b ++ ) {
            if (S.count(a * a + b * b) == 0) 
                S[a * a + b * b] = {a, b};
        }
    
    for (int c = 0; c * c <= n; c ++ ) 
        for (int d = c; d * d + c * c <= n; d ++ ) {
            int t = n - c * c - d * d;
            if (S.count(t)) {
                cout << c << ' ' << d << ' ' << S[t].x << ' ' << S[t].y << endl;
                return 0;
            }
        }
    return 0;
}