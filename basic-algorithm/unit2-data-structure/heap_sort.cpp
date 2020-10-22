#include <iostream>

using namespace std;

const int N = 1e5+5;

int n, m;
int h[N], tt;

void down(int u) {
    int t = u;  // t表示三个数中最小值编号
    if (u * 2 <= tt && h[u * 2] < h[t]) t = u * 2;    // 如果有左儿子并且左儿子比它小更新为左儿子
    if (u * 2 + 1 <= tt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) swap(h[u], h[t]), down(t);      // 当前根节点不是最小的，交换一下，递归处理即可
}

void up(int u) {
    while (u / 2 && h[u / 2] > h[u]) swap(h[u], h[u / 2]), u /= 2;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    tt = n;
    
    // 递归的O(n)建堆，时间不是O(logn)注意
    // 从倒数第二层开始down，保证当前节点的左右儿子已经是堆了
    for (int i = n / 2; i; --i) down(i); 
    
    while (m --) {
        cout << h[1] << ' ';
        h[1] = h[tt];
        tt--;
        down(1);
    }
    
    return 0;
}