// 注意问题中涉及到浮点数
// 通过点的 y 坐标计算得到雷达可能建立的所有位置
// 将问题转化为区间选点问题，尽可能少的点，覆盖所有区间，基础课贪心章节第一个问题
// 右端点排序，使其能覆盖更多的区间。不能覆盖时，更新右端点为新区间的右端点

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1005;

struct Node {
    double l, r;
    bool operator< (const Node &s) const {
        return r < s.r;
    }
}seg[N];

int n, r;

int main() {
    cin >> n >> r;
    for (int i = 0; i < n; i ++ ) {
        int x, y;
        cin >> x >> y;
        if (y > r) {
            puts("-1");
            return 0;
        }
        double dt = sqrt(r * r - y * y);
        seg[i] = {x - dt, x + dt};
    }
    
    sort(seg, seg + n);
    
    int res = 0;
    double r = -1e9;
    for (int i = 0; i < n; i ++ ) 
        if (r < seg[i].l) 
            res ++ , r = seg[i].r;
        
    cout << res << endl;
    
    return 0;
}