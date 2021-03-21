#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100005;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    queue<int> q;
    q.push(1);
    
    long long c = 0, cnt = -100000000, d = 0;
    while (q.size()) {
        d ++ ;
        int len = q.size(); 
        
        long long temp = 0;
        for (int i = 0; i < len; i ++ ) {
            int t = q.front();
            temp += a[t];
            q.pop();
            if ((t << 1) < n) q.push(t << 1);
            if ((t << 1 | 1) < n) q.push(t << 1 | 1);
        }
        if (temp > cnt) cnt = temp, c = d;
    }
    
    cout << c << endl;
    
    return 0;
}


// 简化
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100005;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
   LL maxs = -1e15;
   int depth = 0;
   for (int d = 1, i = 1; i <= n; d ++ , i = i << 1) {            // i 每层的起始位置，即左链下标位置，d 代表层数
       LL cnt = 0;
       for (int j = i; j < 2 * i && j <= n; j ++ ) cnt += a[j];   // 循环 d 层，从 i 开始，均是下标，也可 i+(1<<d-1) 个数2^(d-1)，移位优先级低于+-
       
       if (cnt > maxs) {
           maxs = cnt;
           depth = d;
       }
   }
   
    cout << depth << endl;
    
    return 0;
}