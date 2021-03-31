// 等差数列 (an - a0) / d + 1 即为项数，分子固定，分母求 d 最大，项数最小
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100005;

int n;
int a[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    sort(a, a + n);
    
    int d = 0;
    for (int i = 1; i < n; i ++ ) d = gcd(d, a[i] - a[0]);
    
    if (!d) cout << n << endl;
    else cout << (a[n - 1] - a[0]) / d + 1 << endl;
    
    return 0;
}