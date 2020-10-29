#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5+5;

int n, m;
int e[N], h[N], w[N], ne[N], idx;
int dist[N];
int cnt[N];     // 记录边数
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

// spfa判断负环
bool spfa() {       
    // 在此已经不需要对其进行初始化了，只是判断是否有负环
    // 单源点即便初始化正无穷完毕，也会将dist[1]=0,现在是多源点，也要将dist[i]=0，所以不必要初始化了
    // 也可以这样理解
    // 没有进行dist数组初始化为0x3f3f3f3f，因为当前dist数组并不存储最短路径了，任何值都可，
    // 只要比存在负环造成的负无穷大要大即可，所以0就满足情况，使用默认值即可
    
    
    queue<int> q;
    for (int i = 1; i <= n; ++i) st[i] = true, q.push(i);   // 可能1号点到不了，起始点全部入队
    
    
    
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            // 队列初始时将所有点都加入队列，所以负环一定会发生更新并且一定会发生死循环到达边数为n然后返回true
            if (!st[t]) {
                if (dist[j] > dist[t] + w[i]) {     
                    dist[j] = dist[t] + w[i];
                    cnt[j] = cnt[t] + 1;
                    
                    if (cnt[j] >= n) return true;
                    
                    if (!st[j]) {
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    if (spfa()) puts("Yes");
    else puts("No");
    
    return 0;
}