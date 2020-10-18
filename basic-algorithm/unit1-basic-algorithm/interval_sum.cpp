#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 3e5+5;

int n, m;
int a[N], s[N];     // a数组存储输入x，s数组为前缀和

vector<int> alls;   // alls存储所有下标离散化后的结果
// 插入操作，查询操作
// 每种操作有两个数x,c，采用pair存储
vector<PII> add, query; 

// 采用二分查找，求解输入x离散化后的结果
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;   // 离散化映射为从下标为1开始的自然数，方便前缀和
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});  // 读取插入操作
        
        alls.push_back(x);  // 现将数轴下标加入到待离散化序列中，可能会有重复
    }
    
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        query.push_back({l ,r});  // 读入所有左右区间
        
        alls.push_back(l);  // 离散化区间左右端点
        alls.push_back(r);
    }
    
    // 至此，已经将所有需要离散化的下标放入了alls待离散化数组中去了
    
    // 排序、去重，完成离散化过程
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    // 插入操作
    for (auto e:add) {
        int x = find(e.first);  // 离散化之后的坐标
        a[x] += e.second;       // 在离散化后的坐标中赋值为输入c
    }
    
    // 预处理前缀和
    for (int i = 1; i <= alls.size(); ++i) s[i] = s[i - 1] + a[i];
    
    // 询问操作，直接输出前缀和即可
    for (auto e:query) {
        int l = find(e.first), r = find(e.second); // 离散化后的结果
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}


// 自己实现一个unique函数
vector<int>::iterator unique(vector<int> &a) {
    int j = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (!i || a[i] != a[i - 1])
            a[j ++] = a[i];
    }
    // a[0] --- a[j - 1] 就是a中所有不同的数
    return a.begin() + j;
}

// 调用
alls.erase(unique(alls), alls.end());