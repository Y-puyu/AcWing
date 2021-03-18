#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000005;

int n, m;
int s[N];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> s[i];
    for (int i = n; i >= 1; i -- ) s[i] -= s[i - 1];            // b1 = a1, b2 = a2 - a1, b3 = a3 - a2
    
    while (m -- ) {
        int l, r, c;
        cin >> l >> r >> c;
        
        s[l] += c;
        s[r + 1] -= c;
    }
    
    for (int i = 1; i <= n; i ++ ) s[i] += s[i - 1];
    
    for (int i = 1; i <= n; i ++ ) cout << s[i] << ' ';
    cout << endl;
    
    return 0;
}


#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000005;

int n, m;
int a[N], s[N];

void insert(int l, int r, int c) {
    s[l] += c, s[r + 1] -= c;   
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) insert(i, i, a[i]);            // b1 = a1, b2 = a2 - a1, b3 = a3 - a2
    
    while (m -- ) {
        int l, r, c;
        cin >> l >> r >> c;
        
        insert(l, r, c);
    }
    
    for (int i = 1; i <= n; i ++ ) s[i] += s[i - 1];
    
    for (int i = 1; i <= n; i ++ ) cout << s[i] << ' ';
    cout << endl;
    
    return 0;
}