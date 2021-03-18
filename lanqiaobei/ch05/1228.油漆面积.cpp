// 类似题目，亚特兰蒂斯
// 特殊点：线段树+懒标记+扫描线，懒标记不向下传递，可拓展性很差，建议背过
// 在此线段树维护的是区间，而不是点

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10005;

int n;
struct Segment {
    int x, y1, y2;          // 四元组，x 作为下标，y1 y2 为线段长度，k 两个取值 +1 代表该矩形到来，-1 代表该矩形离开 
    int k;                  // 即 +1 表示 y1y2 这个矩形整体多覆盖了一次 ，-1 表示 y1y2 整体这个区间少覆盖一次
    bool operator< (const Segment &S) const {
        return x < S.x;
    }
} seg[N * 2];               // 线段最多有两倍，一个矩形，对应左边和右边两个线段
struct Node {               // 线段树维护 y 坐标，根节点的值代表当前 x 下至少覆盖一次的矩形的区间总长度，即  高
    int l, r;           
    int cnt, len;           // cnt 当前区间被覆盖的次数，len 至少被覆盖一次的区间的 ---总长度---
} tr[N * 4];                // 线段树需要开节点个数的两倍，根据 y 坐标建立线段树，下标从 0~10000 这里开 N*4 个节点个数，不是 N*2*4 的空间

// 用子节点信息算当前节点的信息
// y总 在亚特兰蒂斯里讲，因为当 k 为 -1，cnt -= 1 操作后，cnt 为 0，表示该段未被覆盖，
// 但是可能之前的叶节点的 len 不为 0，所以现在需要将这个叶节点更新为 0。父节点有叶节点信息提供，所以不用管啦
void pushup(int u) {
    if (tr[u].cnt > 0) tr[u].len = tr[u].r - tr[u].l + 1;    // 如果该区间已经被覆盖过了，长度就是区间长度
    else if (tr[u].l == tr[u].r) tr[u].len = 0;              // 叶节点长度为 0
    else tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;    // 未标记且为非叶节点，则长度为左右儿子长度之和
}
 
// 主要目的就是给所有区间赋两个边界值
void build(int u, int l, int r) {
    tr[u] = {l, r};                     // 按顺序初始化，先赋值，再递归，不能一上来直接判断叶子节点 就 return
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

// 每次修改一个区间的值，懒标记不向下传递
// 一般的区间修改，懒标记都会向下传递，否则将会出错
// 
// 不用传递懒标记的原理：
// 1. 所有操作成对出现，并且先加后减，一定保证线段树  cnt 一定大于等于 0，不会出现小于 0 的情况
// 2. 查询操作只会查询根节点，当 cnt>0 时，len 值已经求出，且能够向下递归的话，那么这两个区间不会是成对的情况，否则应该完全吻合
//    这就造成了向不向下传递都行，反正父节点的信息不会发生改变，祖父节点的信息由父节点提供也不会发生改变，则，根节点信息不发生改变
void modify(int u, int l, int r, int k) {
    if (tr[u].l >= l && tr[u].r <= r) {         // 区间被完全包含
        tr[u].cnt += k;                         // 重复区间被覆盖，非重复，则 -1 减去一层覆盖数，该矩形出去
        pushup(u);
    } else {
        int mid = tr[u].l + tr[u].r >> 1;                   // 向下传递不传递懒标记 
        if (l <= mid) modify(u << 1, l, r, k);
        if (r >= mid + 1) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}


int main() {
    int n;
    cin >> n;
    
    int m = 0;      
    for (int i = 1; i <= n; i ++ ) {            // 线段读入，一个矩形提供两个线段，代表着这个矩形在 x1---x2 这个区间中一直存在
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        seg[m ++ ] = { x1, y1, y2, 1 };         // 矩形进入线段树
        seg[m ++ ] = { x2, y1, y2, -1 };        // 矩形离开线段树   
    }
    
    sort(seg, seg + m);                         // 根据 x 进行排序，共有 2m 个区间，前 m 个为实际的区间。其实 m = 2n，在上面写成 i, i + n 等价
    
    build(1, 0, 10000);                         // 建树，1 号点为根节点。这里还是正常的边界

    int res = 0;
    for (int i = 0; i < m; i ++ ) {
        if (i > 0) res += tr[1].len * (seg[i].x - seg[i - 1].x);  // 从第二条线开始算，构成矩形块，tr[1]是根节点整体的覆盖情况即为高，x差为长
        modify(1, seg[i].y1, seg[i].y2 - 1, seg[i].k);            // 线段树操作的是区间，而不是点，若 y1=0,y2=2，将 0~1 看作区间 0，1~2 区间 1
    }                                                             // 区间的个数会比点的个数少一个，这里就需要 y2-1，指的是修改区间
    
    cout << res << endl;
    
    return 0;
}