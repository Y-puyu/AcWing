#include <iostream>

using namespace std;

const int N = 8;

int d1, d2;
int mon[13] = { 0, 31, 28 , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int s[N];

bool check(int d) {
    int year = d / 10000;
    int month = d % 10000 / 100;
    int day = d % 100;
    
    if (month == 0 || month > 12) return false;
    if (day == 0 || month != 2 && day > mon[month]) return false;
    
    if (month == 2) {
        int leap = year % 4 == 0 && year % 100 || year % 400 == 0;
        if (day > 28 + leap) return false;
    }
    
    return true;
}

int main() {
    cin >> d1 >> d2;
    
    int res = 0;
    for (int i = 1000; i < 10000; i ++ ) {
        int date = i, x = i;
        for (int i = 0; i < 4; i ++ ) date = date * 10 + x % 10, x /= 10;
        if (d1 <= date && d2 >= date && check(date)) res ++ ;
    }
    cout << res << endl;
    return 0;
}


// 题解区大佬是真滴666，不需要考虑平年闰年，枚举月，日，构造出相应的回文年，判断是否在区间内即可
// 且唯一的特殊情况，0229 这个回文年份为 9220 为闰年...很完美的规避了
#include<bits/stdc++.h>
using namespace std;

int a, b;
long long cnt = 0;

int days[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    scanf("%d %d", &a, &b);
    for(int month = 1; month <= 12; month ++){
        for(int day = 1; day <= days[month]; day ++){
            int year = 1000 * (day % 10) + 100 * (day / 10) + 10 * (month % 10) + month / 10;
            int date = 10000 * year + 100 * month + day;
            if(date >= a && date <= b) cnt ++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}