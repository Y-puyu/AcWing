#include <iostream>
using namespace std;

int main() {
    int n, a, res;
    scanf("%d", &n);

    while (n --) {
        res = 0;
        scanf("%d", &a);
        while (a) {
            a &= (a - 1);   // 取出二进制的最后一位1
            ++res;
        }
        printf("%d ", res);
    }
    return 0;
}

#include <iostream>
using namespace std;

int lowbit(int x) {     // lowbit操作，树状数组基本操作
    return x & -x;
}

int main() {
    int n, a, res;
    scanf("%d", &n);
    
    while (n --) {
        res = 0;
        scanf("%d", &a);
        while (a) {
            a -= lowbit(a);
            ++res;
        }
        printf("%d ", res);
    }
    return 0;
}