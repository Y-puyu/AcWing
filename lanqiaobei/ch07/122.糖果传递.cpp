// 完全数学+推公式，推到绝对值不等式转化为中位数模型
// 糖果为单向传递。若为双向不带环传递的话，转化为单向传递即可，因为总的消耗是不变的
// 
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 5;

int n;
int a[N];
LL c[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    LL avg = 0;
    for (int i = 0; i < n; i ++ ) avg += a[i];
    
    avg /= n;
    
    c[0] = 0;
    for (int i = n - 1; i > 0; i -- ) {
        c[i] = c[i + 1] + avg - a[i];
    }
    
    sort(c, c + n);
    
    LL res = 0;
    for (int i = 0; i < n; i ++ ) res += abs(c[i] - c[n / 2]);
    
    cout << res << endl;
    
    return 0;
}