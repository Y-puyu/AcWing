#include <iostream>

using namespace std;

int n;

bool check(int u) {
    while (u) {
        int t = u % 10;
        if (t == 2 || t == 1 || t == 0 || t == 9) return true;
        u /= 10;
    }
    return false;
}

int main() {
    cin >> n;
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (check(i))
            res += i;
            
    cout << res << endl;
    
    return 0;
}