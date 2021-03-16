// 按照题目输入，时间将会非常的杂乱，导致同时间 同店铺的订单会进行重复处理
// 根据时间排序后，则仅需将相同时间 店铺的订单 打包 来进行统一处理
// 故不需要枚举时间 再枚举店铺
// 仅需要按照时间排序后，由时间次序从小到大依次对不同店铺进行处理即可
// 需要维护的信息：一店铺同时间订单的数量，上一次接单的时间点
// 由数量做到打包处理，由接单时间点做到能量的衰减与增加，上一次接单时间 last[i] 距离本次接单时间t 中间间隔
// t - last[i] - 1 个时间，例如 上一次接单为 2 ，本次为 5 中间仅为 5 - 2 - 1 = 2 的能量衰减
// 先计算衰减能量，再判断是否在优先缓存中
// 再判断本次接单所增加的能量，再判断是否在优先缓存中
// 循环遍历店铺，判断每个店铺到末尾时间的能量衰减，只考虑衰减即可，若末尾时间有订单则已经考虑完毕，且last[i]=T也已经更新过了
// 最后判断st数组中仍为优先缓存中的店铺数量即可

#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100005;

int n, m, T;
int score[N], last[N];      // score[i]表示第i个店铺的优先级，last[i]表示第i个店铺上一个订单的时刻
bool st[N];                 // st[i]表示第i个店铺是否存在优先缓存中
PII order[N];               // order[i]表示第i个店铺的下单时间 及 id

int main() {
    cin >> n >> m >> T;
    
    for (int i = 0; i < m; i ++ ) cin >> order[i].x >> order[i].y;
    
    sort(order, order + m);         // 以时间进行排序
    
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && order[j] == order[i]) j ++ ;        // 找到同一批订单，排序后，t,id 完全相同这必然相邻，双指针找就行了
        int t = order[i].x, id = order[i].y, cnt = j - i;
        i = j;
        
        score[id] -= t - last[id] - 1;          // 处理 t 时间没订单的空余其，能量衰减
        if (score[id] < 0) score[id] = 0;
        if (score[id] <= 3) st[id] = false;
        
        score[id] += cnt * 2;                   // 处理t时刻下的订单，能量增长
        if (score[id] > 5) st[id] = true;
        last[id] = t;
    }
    
    for (int i = 1; i <= n; i ++ ) {            // 循环每个店铺，查看最后一段时间是否有订单，没订单得进行能量衰减，踢出优先缓存
        if (last[i] < T) {                      // 若 T 时刻下有订单，则被更新过，last[i]将等于 T，反之直到最后都没有订单，自然能量衰减
            score[i] -= T - last[i];
            if (score[i] <= 3) 
                st[i] = false;
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (st[i])
            res ++ ;
    
    cout << res << endl;
    
    return 0;
}