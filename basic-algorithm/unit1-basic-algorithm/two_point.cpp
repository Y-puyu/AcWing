#include <iostream>

using namespace std;

const int N = 1e5+5;

int n;
int a[N], s[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = -1;
    for (int i = 0, j = 0; i < n; ++i) {
        // s数组做[j, i]区间中数字出现次数的哈希数组
        s[a[i]]++;

        // 在此可以省略j <= i，s数组可以判断
        while (j <= i && s[a[i]] > 1) s[a[j]]--, ++j;   
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}