// 在该题目要求下，符合要求的灵能传输一次，相当于将自己和自己前面的前缀和做交换，即 si-1  si  si+1   变为 si   si-1   si+1
// 最终求 ai 最小的情况，即求解相邻两项前缀和序列的最小值，两两交换可以得到任意序列的前缀和
// 但是 s0   sn  是不允许移动的
// 当 s0  sn 可以移动时，单调序列就是最优序列，单调序列的相邻两项最为接近，差值最小
// 当 s0  sn 不可移动时，整个前缀和区间中一定存在一个最大值，一个最小值。且 s0 sn 位置无法移动，
//                       则函数大致为一个开口向上的二次函数和一个开口向下的二次函数拼接。若先开口向上再是向下，则重复段会变多，不是最优解
//                       再就是 0.......s0........sn......n 如何遍历完这些点，从 s0-->0--->n--->sn
// 步长为 2 最符合要求，不重不漏能全部跳完。。。这点证明属实太6
// 若有一个步长为 1 的，则有一段必然是步长为 3 才能跳完，那么就不如步长为 2 的好。。。
// 其它情况同理可证
// 步长主要为 2 ，步长为 1 处理一些边界情况，就能完成所有跳跃！
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 3e5+5;

int n;
LL a[N], s[N];
bool st[N];

int main() {
    int T;
    cin >> T;
    
    while (T -- ) {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        
        
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
        LL s0 = s[0], sn = s[n];
        
        if (s0 > sn) swap(s0, sn);      // 每次只处理 s0 小  sn 大的情况
        
        sort(s, s + n + 1);     
        
        for (int i = 0; i <= n; i ++ ) {
            if (s[i] == s0) {
                s0 = i;
                break;
            }
        }
        
        for (int i = n; i >= 0; i -- ) {            // 其中 s0 sn 可能在中间多次相等，sn 取后面那个即可
            if (s[i] == sn) {
                sn = i;
                break;
            }
        }
        
        memset(st, 0, sizeof st);
        
        int l = 0, r = n;
        for (int i = s0; i >= 0; i -= 2) {        // .....s0....sn....  从s0开始以步长为 2 往左跳
            a[l ++ ] = s[i];
            st[i] = true;
        }
        
        for (int i = sn; i <= n; i += 2) {       // sn....n 从 sn 跳到 n，步长为 2 往右跳
            a[r -- ] = s[i];
            st[i] = true;
        }
        
        for (int i = 0; i <= n; i ++ ) {        // 0.....n  从 0 跳到 n，步长为 1 为 2 都行，有些点已经被跳过了，自然就是 2 
            if (!st[i])                         // 反倒步长为 1 会很轻松的少处理边界情况，奇偶情况就不需要再考虑了
                a[l ++ ] = s[i];
        }
        
        LL res = 0;
        for (int i = 1; i <= n; i ++ ) res = max(res, abs(a[i] - a[i - 1]));
        
        cout << res << endl;
    }
    return 0;
}