#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5+5;

int n;
vector<PII> a;

void merge(vector<PII> &a) {
    vector<PII> res;    // 存储合并后的结果
    
    sort(a.begin(), a.end());
    
    int st = -2e9, ed = -2e9;   // 当前维护区间的左右端点
    
    for (auto e:a) {
        if (ed < e.first) {     // 无交集，找到了新区间
            if (st != -2e9) res.push_back({st, ed});    // 不能是初始区间
            
            st = e.first, ed = e.second;    // 新区间是初始区间，更新左右端点
        }
        else ed = max(ed, e.second);    
    }
    
    // 加入最后一个区间，且防止是空区间情况
    if (st != -2e9) res.push_back({st, ed}); 
    
    a = res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r});
    }
    
    merge(a);
    
    cout << a.size() << endl;
    
    return 0;
}