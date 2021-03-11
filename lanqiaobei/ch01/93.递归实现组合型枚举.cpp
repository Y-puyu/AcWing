// 组合类型枚举不允许数字的重复出现，这点不同于排列型枚举
// 故可以枚举时定义一个递增的序来保证数字的不重复出现及枚举的唯一性

// 简单修改排列型枚举的代码
#include <iostream>

using namespace std;

const int N = 25;

int n, m;
int a[N];
int st[N];

void dfs(int u) {
    if (u > m) {
        for (int i = 1; i <= m; i ++ ) 
            cout << a[i] << ' ';
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i ++ ) {
        if (!st[i] && a[u - 1] < i) {
            a[u] = i;
            st[i] = 1;
            dfs(u + 1);
            a[u] = 0;
            st[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}

// 标准新写法，最优，判断最少
#include <iostream>

using namespace std;

const int N = 25;

int n, m;
int a[N];

void dfs(int u, int start) {                // 多一个参数，少一个数组
    if (u > m) {
        for (int i = 1; i <= m; i ++ ) 
            cout << a[i] << ' ';
        cout << endl;
        return ;
    }
    
    for (int i = start; i <= n; i ++ ) {
        a[u] = i;
        dfs(u + 1, i + 1);
        a[u] = 0;
    }

}

int main() {
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}


// 简单写法，多一个判断，代码效率低，与上面差了 6 倍
#include <iostream>

using namespace std;

const int N = 25;

int n, m;
int a[N];

void dfs(int u) {                // 多一个参数，少一个数组
    if (u > m) {
        for (int i = 1; i <= m; i ++ ) 
            cout << a[i] << ' ';
        cout << endl;
        return ;
    }
    
    for (int i = 1; i <= n; i ++ ) {
        if (a[u - 1] < i) {
            a[u] = i;
            dfs(u + 1);
            a[u] = 0;
        }
    }

}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}


// 剪枝优化
#include <iostream>

using namespace std;

const int N = 25;

int n, m;
int a[N];

void dfs(int u, int start) {             
    // 剪枝优化，已经选择 u-1 个数，后面还有 n-start+1 个数，若两者和小于 m，则剪枝退出
    if (u + n - start < m) return ;
    if (u > m) {
        for (int i = 1; i <= m; i ++ ) 
            cout << a[i] << ' ';
        cout << endl;
        return ;
    }
    
    
    for (int i = 1; i <= n; i ++ ) {
        if (a[u - 1] < i) {
            a[u] = i;
            dfs(u + 1, i + 1);
            a[u] = 0;
        }
    }

}

int main() {
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}