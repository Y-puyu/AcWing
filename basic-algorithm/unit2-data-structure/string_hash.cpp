#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5+5, mod = 13331;

int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m >> str + 1;
    
    p[0] = 1;
    for (int i = 1; str[i]; ++i) {
        p[i] = p[i - 1] * mod;    
        h[i] = h[i - 1] * mod + str[i];
    }
    
    while (m --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        if(get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}