// 最优解中，任何一个跨度大于一天的交易，一定能被分解为连续个一天的交易
// 若存在中间亏钱的交易，则完全可以将其拆分，避免亏钱，使得收益最大化

#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    int res = 0;
    for (int i = 1; i < n; i ++ ) 
        if (a[i] > a[i - 1])
            res += a[i] - a[i - 1];
    cout << res << endl;
    return 0;
}