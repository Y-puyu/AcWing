#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

int n;
int st[N];  // 0 未考虑，1 选，2 不选

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++ ) 
            if (st[i] == 1)
                cout << i + 1 << ' ';
        cout << endl;
        return ;
    }
    
    st[u] = 2;
    dfs(u + 1);
    st[u] = 0;
    
    st[u] = 1;
    dfs(u + 1);
    st[u] = 0;
    
}

int main() {
    cin >> n;
    
    dfs(0);
    
    return 0;
}

// 保存方案
#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n;
int st[N];
vector<vector<int>> ways;

void dfs(int u) {
    if (u == n) {
        vector<int> way;
        for (int i = 0; i < n; i ++ ) 
            if (st[i] == 1) 
                way.push_back(i + 1);
        ways.push_back(way);
        return ;
    }
    
    st[u] = 2;
    dfs(u + 1);
    st[u] = 0;
    
    st[u] = 1;
    dfs(u + 1);
    st[u] = 0;
}

int main() {
    cin >> n;
    dfs(0);
    
    for (int i = 0; i < ways.size(); i ++ ) {
        for (int j = 0; j < ways[i].size(); j ++ )
            cout << ways[i][j] << ' ';
        cout << endl;
    }
    return 0;
}