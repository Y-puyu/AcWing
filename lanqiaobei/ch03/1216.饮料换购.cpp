#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    
    int res = n;
    while (n >= 3) {
        res += n / 3;
        n = n / 3 + n % 3;
    }
    
    cout << res << endl;
    return 0;
}



// 模拟，直接队列搞也行，队首出队 3 个，队尾进队一个，计数即可