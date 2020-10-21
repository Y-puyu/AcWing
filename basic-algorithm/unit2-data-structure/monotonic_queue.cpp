#include <iostream>

using namespace std;

const int N = 1e6+5;

int n, k;
int a[N], q[N], hh, tt;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {       // 最小值
        // 判断队头是否已经划出窗口
        if (hh <= tt && i - k + 1 > q[hh]) hh ++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++ tt] = i;   // 要在if前把i加进去，因为如果a[i]很小，把队列全部清空，应该是返回a[i]的
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
    puts("");
    
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {       // 最大值   仅需要改变while的小于等于即可
        // 判断队头是否已经划出窗口
        if (hh <= tt && i - k + 1 > q[hh]) hh ++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
    
    return 0;
}