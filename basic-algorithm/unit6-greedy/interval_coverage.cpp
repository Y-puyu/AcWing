#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;
struct Range {
    int l, r;
    bool operator<(const Range &W) const {
        return l < W.l;
    }
}range[N];

int main() {
    int st, ed;
    cin >> st >> ed;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    int res = 0;
    bool success = false;                    // 判断是否成成功覆盖
    for (int i = 0; i < n; ++i) {            // 枚举所有区间，区间已经按照左端点进行排序
        int j = i, r = -2e9;
        while (j < n && range[j].l <= st) {  // 双指针遍历所有左端点在st左边的区间右端点的最大值
            r = max(r, range[j].r);          
            ++j;
        }
        if (r < st) {                        // 如果当前最大的区间右端点都无法到达st,那么则无法覆盖，覆盖失败返回-1
            res = -1;
            break;
        }
        ++res;                               // 可以覆盖，区间数++
        if (r >= ed) {                       // 如果所选区间加上已经大于了ed，则覆盖完毕
            success = true;
            break;
        }
        st = r;                              // 更新起点
        i = j - 1;                           // 更新双指针位置,注意在此是i=j-1而不是i=j,循环中i还会++,j已经指向了下一个区间位置
                                             // 需要的是将i更新到j的位置上来，不要让i在此加两遍...是一个双指针模板,搁着debug了好久....
    }
    if (!success) res = -1;
    cout << res << endl;
    
    return 0;
}