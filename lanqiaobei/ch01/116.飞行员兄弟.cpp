#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 5;

char g[N][N], backup[N][N];

int get(int x, int y) {
    return x * 4 + y;
}

void turn_one(int x, int y) {
    if (g[x][y] == '+') g[x][y] = '-';
    else g[x][y] = '+';
}

void turn_all(int x, int y) {
    for (int i = 0; i < 4; i ++ ) {
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y);
}

int main() {
    for (int i = 0; i < 4; i ++ ) cin >> g[i];
    
    memcpy(backup, g, sizeof g);
    
    vector<PII> res;
    for (int op = 0; op < 1 << 16; op ++ ) {
        vector<PII> temp;
        for (int i = 0; i < 4; i ++ ) 
            for (int j = 0; j < 4; j ++ ) 
                if (op >> get(i, j) & 1) {
                    temp.push_back({i, j});
                    turn_all(i, j);
                }
        
        bool has_close = false;
        for (int i = 0; i < 4; i ++ ) 
            for (int j = 0; j < 4; j ++ ) 
                if (g[i][j] == '+')
                    has_close = true;
        
        if (!has_close) 
            if (res.empty() || res.size() > temp.size()) 
                res = temp;
        
        memcpy(g, backup, sizeof g);
    }
    cout << res.size() << endl;
    for (auto e : res) cout << e.x + 1<< ' ' << e.y + 1<< endl;
    return 0;
}