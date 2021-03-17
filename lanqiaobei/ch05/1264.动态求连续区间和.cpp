#include <iostream>

using namespace std;

const int N = 100005;

int n, m;
int a[N], tr[N];
int k, l, r;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) add(i, a[i]);
    
    while (m -- ) {
        cin >> k >> l >> r;
        
        if (k == 1) add(l, r);
        else if (k == 0) cout << query(r) - query(l - 1) << endl;
    }
    return 0;
}


#if 0

#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int w[N];
struct Node {
    int l, r;
    int sum;
} tr[4 * N];

// 关于开 4n 的空间，由于叶子节点只会出现在最后一层及倒数第二层，且倒数第二层节点个数至多不会超过n，则倒数第二层至顶层节点总数将不会超过2n
// 且最后一层节点自然也不会超过2n,则总共的节点总数不会超过4n，是一个经验值，有些地方3n也能过，但没必要

// 用子节点信息更新父节点信息，只有节点是父节点时，才有权调用该函数，否则我感觉在叶子节点调用时可能会有越界风险，故后续一定要吧叶子节点信息维护好
void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;        // 当前节点值为左右儿子值之和
}

// 在区间上初始化线段树
void build(int u, int l, int r) {
    if (l == r) tr[u] = { l, r, w[r] };                     // 叶节点，就是自己,w[r] 就是对应线段树位置的sum
    else {
        tr[u] = { l, r };       // 赋给区间初值，父节点一定是有两个孩子的节点
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);       // 建立父节点u的左右儿子节点，返回时已经建立出来叶节点了
        pushup(u);                                          // 当前是父节点u位置，左右儿子节点刚刚被建立，则信息向上传递，更新父节点信息
    }
}

// 查询操作，至多 O(4logn) 的时间复杂度
// 错误的更新区间方式 if(l<=mid)sum=query(u<<1,l,mid); if(r>mid)sum+=query(u<<1|1,mid+1,r);
// 当l <= mid时，r也可能比mid小，此时如果把r更新成mid，那就会错误地把要查询的区间变长
int query(int u, int l, int r) {        // 函数传参l,r一直不变，这点就很大不同，实际上真正有用的区间很少，中间经过的均只是回溯路径罢了
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;     // 如果已经被完全包含，就说明其是一个有效的区间，准备回溯返回
    int mid = tr[u].l + tr[u].r >> 1;   // 根据build()函数进行查询，每次找一半
    int sum = 0;
    if (l <= mid) sum = query(u << 1, l, r);    // 在此 sum += 也无所谓，因为初值是 0，左边已经被完全包含
    if (r >= mid + 1) sum += query(u << 1 | 1, l, r);  // l
    return sum;
}

int modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) tr[u].sum += v; // 当前叶节点。且不用pushup，因为pushup操作在父节点那一层进行，修改后再查询就是修改后的结果了
    else {
        int mid = tr[u].l + tr[u].r >> 1;   // 不为叶节点则一直二分往下找,最终肯定能找到叶节点,pushup操作依次回溯更新父节点即可
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];             // 下标从 1 开始，左儿子 i * 2,右儿子 i*2+1，父节点 floor(i / 2)
    
    build(1, 1, n);     // 根节点下标，根节点区间
    
    int k, a, b;
    while (m -- ) {
        cin >> k >> a >> b;
        if (k == 0) cout << query(1, a, b) << endl;         // 对 [a,b] 区间进行求和，根节点位置，左端点，右端点
        else modify(1, a, b);                               // 对 a 位置的数进行修改操作，可加可修改，数为  b
    }
    
    return 0;
}

#endif 