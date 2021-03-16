#include <iostream>

using namespace std;

int w, m, n;

int main() {
    cin >> w >> m >> n;
    m -- , n -- ;
    int x1, y1, x2, y2;
    x1 = m / w, x2 = n / w;
    y1 = x1 & 1 ? w - 1 - m % w : m % w;
    y2 = x2 & 1 ? w - 1 - n % w : n % w;
    
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    
    return 0;
}