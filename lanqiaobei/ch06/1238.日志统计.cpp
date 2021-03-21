#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100005;

int n, d, k;
PII logs[N];
int cnt[N];
bool st[N];

int main() {
    cin >> n >> d >> k;
    
    for (int i = 0; i < n; i ++ ) cin >> logs[i].x >> logs[i].y;
    
    sort(logs, logs + n);
    
    for (int i = 0, j = 0; i < n; i ++ ) {
        int id = logs[i].y;
        cnt[id] ++ ;
        
        while (logs[i].x - logs[j].x >= d) cnt[logs[j ++ ].y] -- ;
        
        if (cnt[id] >= k) st[id] = true;
    }
    
    int res = 0;
    for (int i = 0; i < 100000; i ++ )          // 在这遍历的是 id，不是 n... 大意了啊
        if (st[i]) 
            cout << i << endl;
    
    return 0;
}