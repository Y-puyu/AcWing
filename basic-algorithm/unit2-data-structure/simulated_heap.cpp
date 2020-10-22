#include <iostream>
#include <string.h>

using namespace std;

const int N = 1e5+5;

int n, m;
// h存堆中元素数值
// ph[j]=k,表示第j个插入点在堆中的下标是k
// hp[k]=j,表示堆中第k个点对应的ph数组的下标是j，两者互逆 
// 因为需要从插入点找到堆中元素，又需要从堆中元素找回插入点
int h[N], ph[N], hp[N], tt; 

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]); // 堆中的下标交换，hp[a]是堆中的下标对应到ph的下标
    swap(hp[a], hp[b]);         // hp由于堆中下标变换了，所以也需要跟着改变一下，指向对应的ph数组
    swap(h[a], h[b]);           // 值交换
}

void down(int u) {
    int t = u;
    if (u * 2 <= tt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= tt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) heap_swap(u, t), down(t);
}

void up(int u) {
    while (u / 2 && h[u / 2] > h[u]) heap_swap(u / 2, u), u /= 2;
}

int main() {
    cin >> n;
    while (n --) {
        char op[10];
        int k, x;
        cin >> op;
        if (!strcmp(op, "I")) {         // 插入操作
            cin >> x; 
            tt++, m++;                  // m为插入的次数
            ph[m] = tt;                 // 第m个插入的数，在堆中就是tt位置
            hp[tt] = m;                 // 堆中tt位置的数就是第m个插入的数
            h[tt] = x;
            up(tt);
        } 
        else if (!strcmp(op, "PM")) cout << h[1] << endl;       // 输出最小值
        else if (!strcmp(op, "DM")) {                           // 删除最小值
            heap_swap(1, tt);
            tt--;
            down(1);
        } 
        else if (!strcmp(op, "D")) {                            // 删除第k个插入的数
            cin >> k;
            k = ph[k];                                          // ph[k]是第k个数在堆中的位置
            heap_swap(k, tt);
            tt--;
            down(k), up(k);
        }
        else {                                                  // 修改第k个插入的数
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}