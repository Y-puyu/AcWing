#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    int res = 1;
    if (a[1] > 0) {
        for (int i = 2; i <= n; i ++ ) {
            if (a[i] < 0 && abs(a[i]) >= a[1])
                res ++ ;
        }
        for (int i = 2; i <= n; i ++ )
            if (a[i] > 0 && res > 1 && a[i] < a[1])
                res ++ ;
        cout << res << endl;
        return 0;
    } else {
        for (int i = 2; i <= n; i ++ )
            if (a[i] > 0 && a[i] <= abs(a[1])) 
                res ++ ;
        for (int i = 2; i <= n; i ++ )
            if (a[i] < 0 && res > 1 && abs(a[i]) >= abs(a[1]))
                res ++ ;
        cout << res << endl;
        return 0;
    }
    return 0;
}

// 简单写法
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    int l = 0, r = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (abs(a[i]) < abs(a[1]) && a[i] > 0) l ++ ;
        else if (abs(a[i]) > abs(a[1]) && a[i] < 0) r ++ ;
    }
    if (a[1] < 0 && l == 0 || a[1] > 0 && r == 0) cout << 1 << endl;
    else cout << l + r + 1 << endl;
    
    return 0;
}