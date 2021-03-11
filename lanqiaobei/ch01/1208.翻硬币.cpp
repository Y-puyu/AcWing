#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;

char g[N], G[N];

int main() {
    cin >> g >> G;
    int n = strlen(g);
    
    int res = 0;
    for (int i = 0; i < n - 1; i ++ ) {
        if (g[i] != G[i]) { 
            if (g[i] == '*') g[i] = 'o';
            else g[i] = '*';
            
            if (g[i + 1] == '*') g[i + 1] = 'o';
            else g[i + 1] = '*';
            res ++ ;
        }
    }
    cout << res << endl;
    return 0;
}