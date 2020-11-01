#include <iostream>
#include <algorithm>

using namespace std;

int m;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; ++i) 
        if (n % i == 0) 
            return false;
    
    return true;
}

int main() {
    cin >> m;
    while (m --) {
        int n;
        cin >> n;
    
        if (is_prime(n)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}