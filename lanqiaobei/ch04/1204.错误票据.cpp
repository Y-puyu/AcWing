#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;

int n;
int a[N];

int main() {
    cin >> n;
    int i = 0, cnt = 0;
    while (~scanf("%d", &a[i ++ ])) cnt ++ ;
    
    sort(a, a + cnt);
    
    int c = 0, d = 0;
    for (int i = 0; i < cnt - 1; i ++ ) {
        if (a[i] + 2 == a[i + 1]) c = a[i] + 1;
        if (a[i] == a[i + 1]) d = a[i];
        if (c && d) break;
    }
    
    cout << c << ' ' <<  d;
    
    return 0;
}


// stringstream 的 应用
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int n;
int a[N];

int main()
{
    int cnt;
    cin >> cnt;         // 数字读完之后，后面有一个回车得将其忽略
    string line;

    getline(cin, line); // 忽略掉第一行的回车
    while (cnt -- )
    {
        getline(cin, line);
        stringstream ssin(line);        // ssin 将和 cin 具有同等读入数据的形式，不过操作对象的string类型

        while (ssin >> a[n]) n ++ ;
    }

    sort(a, a + n);

    int res1, res2;
    for (int i = 1; i < n; i ++ )
        if (a[i] == a[i - 1]) res2 = a[i];  // 重号
        else if (a[i] >= a[i - 1] + 2) res1 = a[i] - 1; // 断号

    cout << res1 << ' ' << res2 << endl;

    return 0;
}