#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5+5;

int n;
struct Range {
    int l, r;
    bool operator< (const Range &W) {
        return l < W.l;
    }
}range[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; ++i) {
        auto r = range[i];
        if (heap.empty() || heap.top() >= r.l) heap.push(r.r);
        else {
            int t = heap.top();
            heap.pop();
            heap.push(r.r);
        }
    }
    
    cout << heap.size() << endl;
    
    return 0;
}