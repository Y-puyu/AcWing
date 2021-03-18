#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2000005;      // 三维情况下，下标从 1 开始，就需要多三个面，但最坏情况下只有一个面，也只能多一个面就需要多开一倍空间

int A, B, C, m;             // 保证乘积小于 1e6，其中任意一个都可能取到 1e6，故需要开一个一维数组，自行映射到三维中去
LL s[N], b[N], bp[N];       //  s 原数组，b 差分数组，bp 二分前的备份数组 
int op[N / 2][7];           // 1e6 个操作，每个操作 7 个数 

int d[8][4] = {
    {0, 0, 0, 1},
    {0, 0, 1, -1},
    {0, 1, 0, -1},
    {0, 1, 1, 1},
    {1, 0, 0, -1},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, -1}
}; 

int get(int x, int y, int z) {          // 相当于是优先 z 轴，竖起来进行一个一维意义下的存储
    return (x * B + y) * C + z;
}

bool check(int mid) {
    memcpy(b, bp, sizeof bp);           // 拷贝差分数组
    
    for (int i = 1; i <= mid; i ++ ) {
        int x1 = op[i][0], x2 = op[i][1], y1 = op[i][2], y2 = op[i][3], z1 = op[i][4], z2 = op[i][5], h = op[i][6];
        b[get(x1,     y1,     z1)]     -= h;
        b[get(x1,     y1,     z2 + 1)] += h;
        b[get(x1,     y2 + 1, z1)]     += h;
        b[get(x1,     y2 + 1, z2 + 1)] -= h;
        b[get(x2 + 1, y1,     z1)]     += h;
        b[get(x2 + 1, y1,     z2 + 1)] -= h;
        b[get(x2 + 1, y2 + 1, z1)]     -= h;
        b[get(x2 + 1, y2 + 1, z2 + 1)] += h;
    }
    
    memset(s, 0, sizeof s);             // 清空，准备求前缀和
    for (int i = 1; i <= A; i ++ )
        for (int j = 1; j <= B; j ++ )
            for (int k = 1; k <= C; k ++ ) {
                s[get(i, j, k)] = b[get(i, j, k)];          // 三维前缀和，先累加第一项
                for (int u = 1; u < 8; u ++ ) {             // 循环后 7 项
                    int x = i - d[u][0], y = j - d[u][1], z = k - d[u][2], t = d[u][3];
                    s[get(i, j, k)] -= s[get(x, y, z)] * t; // 符号相反，和上面定义的符号
                }

                if (s[get(i, j, k)] < 0) return true;
            }

    return false;
}


int main() {
    cin >> A >> B >> C >> m;
    
    for (int i = 1; i <= A; i ++ )
        for (int j = 1; j <= B; j ++ )
            for (int k = 1; k <= C; k ++ ) 
                scanf("%lld", &s[get(i, j, k)]);    // 将三维坐标映射到一维数组中
                
                
    for (int i = 1; i <= A; i ++ )
        for (int j = 1; j <= B; j ++ ) 
            for (int k = 1; k <= C; k ++ )
                for (int u = 0; u < 8; u ++ ) {
                    int x = i - d[u][0], y = j - d[u][1], z = k - d[u][2], t = d[u][3];
                    bp[get(i, j, k)] += s[get(x, y, z)] * t;        // 三维前缀和，移项后转化为差分数组
                }
    
    for (int i = 1; i <= m; i ++ )
        for (int j = 0; j < 7; j ++ )
            scanf("%d", &op[i][j]);
    
    int l = 1, r = m;
    while (l < r) {                     // 二分
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    printf("%d\n", r);
    
    return 0;
}