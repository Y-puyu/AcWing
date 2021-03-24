// 经典中位数模型

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    sort(a, a + n);
    
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += abs(a[i] - a[n / 2]);
    cout << res << endl;
    return 0;
}