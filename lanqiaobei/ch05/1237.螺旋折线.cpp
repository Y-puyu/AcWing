// 有数据范围----> 找规律的题目，纯靠数字敏感性和分析
// 画个大表，打表来做
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    int x, y;
    cin >> x >> y;
    
    if (abs(x) <= y) {                      // 上
        int n = y;
        cout << (LL)(2 * n - 1) * (2 * n) + x - (-n) << endl;
    } else if (abs(y) <= x) {               // 右
        int n = x;
        cout << (LL)(2 * n) * (2 * n) + n - y << endl;
    } else if (abs(x) <= abs(y) + 1 && y < 0) {      // 下
        int n = abs(y);
        cout << (LL)(2 * n + 1) * (2 * n) + n - x << endl;
    } else {                                // 左
        int n = abs(x);
        cout << (LL)(2 * n - 1) * (2 * n - 1) + y - (-n + 1) << endl;
    }
    
    return 0;
}