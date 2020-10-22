// 开放寻址法
#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5+3;  // 大于20w的第一个质数
const int null = 0x3f3f3f3f;    // 超越数据范围作为数据不在哈希表中的一个标记

int h[N];

// 如果x在哈希表存在则返回在哈希表中的位置
// 若不存在，则返回应该在哈希表中存放的位置
int find(int x) {
    int k = (x % N + N) % N;
    
    while (h[k] != null && h[k] != x) { // 如果哈希表该位置有人，并且不为x
        k ++;               // 找下一个坑位
        if (k == N) k = 0;  // 找完了，从头开始
    }
    return k;
}

int main() {
    memset(h, 0x3f, sizeof h);    // 清空所有槽，-1 代表空指针，该位置没元素
    int n;
    cin >> n;
    while (n --) {
        char op[2];
        int x;
        cin >> op >> x;
        int k = find(x);
        if (op[0] == 'I') h[k] = x;
        else {
            if (h[k] != null) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}