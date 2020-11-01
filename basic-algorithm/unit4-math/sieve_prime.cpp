#include <iostream>
using namespace std;

const int N = 1e6+10;
int n, cnt;
int primes[N];
bool st[N];

// 线性筛
void get_prime(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            primes[cnt ++] = i;
        }
        for (int j = 0; primes[j] <= n / i; ++j) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }

    }
}

int main() {
    scanf("%d", &n);
    get_prime(n);
    cout << cnt << endl;
    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6+5;

int n;
int prime[N], cnt;
bool st[N];

// 埃筛
void get_primes(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            prime[cnt ++] = n;
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
        

    }
}

int main() {
    cin >> n;
    
    get_primes(n);
    
    cout << cnt << endl;
    
    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6+5;

int n;
int prime[N], cnt;
bool st[N];

// 朴素埃筛
void get_primes(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            prime[cnt ++] = n;
        }
        
        for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}

int main() {
    cin >> n;
    
    get_primes(n);
    
    cout << cnt << endl;
    
    return 0;
}