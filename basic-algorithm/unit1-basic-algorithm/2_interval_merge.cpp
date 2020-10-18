#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

struct Node {
    int k, l, r;
    bool operator<(const Node& w) const {   // 按行列、左端点、右端点优先级排序
        if (k != w.k) return k < w.k;
        else if (l!= w.l) return l < w.l;
        else return r < w.r;
    }
};

int n;
LL cnt;
vector<Node> cols, rows;

void merge(vector<Node> &segs) {
    sort(segs.begin(), segs.end());
    
    vector<Node> res;
    
    int st = -2e9, ed = -2e9, k = -2e9;
    for (auto seg:segs) {
        if (seg.k == k) {   // 保证在同一行/列
            if (ed < seg.l) {   // 无法区间合并，即发现新区间
                if (st != -2e9) {   // 若不是初始区间
                    res.push_back({k, st, ed});
                    cnt += ed - st + 1;
                } 
                st = seg.l, ed = seg.r; // 无法合并，更新区间左右端点
            } else {
                ed = max(ed, seg.r);    // 合并区间，更新右端点
            } 
        } else {    // 不在同一行/列，直接就是个新区间，不能进行区间合并
            if (st != -2e9) {   // 若不为初始区间
                res.push_back({k, st, ed});
                cnt += ed - st + 1;
            }
            k = seg.k, st = seg.l, ed = seg.r;  // 更新成这个新区间的左右端点和行/列k值
        }
    }
    
    // 最后一个区间一个区间for循环无法处理，自行保存，且需要防止为空区间输入
    if (st != -2e9) res.push_back({k, st, ed}), cnt += ed - st + 1;
    
    segs = res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) cols.push_back({x1, min(y1, y2), max(y1, y2)});
        else rows.push_back({y1, min(x1, x2), max(x1, x2)});
    }
    
    merge(cols), merge(rows);
    
    for (auto col:cols)
        for (auto row:rows) 
            if (row.k >= col.l && row.k <= col.r && row.r >= col.k && row.l <= col.k) cnt --;
    
    cout << cnt << endl;
    
    return 0;
}