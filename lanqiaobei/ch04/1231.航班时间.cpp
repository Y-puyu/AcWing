// 北京到中东：飞行时间 = 去程起降时间差 - 时差
// 中东到北京：飞行时间 = 回程起降时间差 + 时差
// 所以 飞行时间 = (去程起降时间差+回程起降时间差)/2
// "当地时间”
// A地起飞时间    B地降落时间
// 
// B地起飞时间    A地降落时间

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int get_second(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int get_time() {
    string str;
    getline(cin, str);
    if (str.back() != ')') str += " (+0)";
    
    int h1, m1, s1, h2, m2, s2, d;
    sscanf(str.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
    
    return get_second(h2, m2, s2) - get_second(h1, m1, s1) + d * 24 * 60 * 60;
}

int main() {
    int T;
    cin >> T;
    string line;
    getline(cin, line);     // 忽略第一行的空格
    
    while (T -- ) {
        int t = get_time() + get_time() >> 1;
        int h = t / 3600, m = t % 3600 / 60, s = t % 60;
        printf("%02d:%02d:%02d\n", h, m, s);
    }
    return 0;
}