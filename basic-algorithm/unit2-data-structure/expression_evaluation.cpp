#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

stack<int> num;
stack<char> op;
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval() {
    int b = num.top();num.pop();
    int a = num.top();num.pop();
    
    if (op.top() == '+') num.push(a + b);
    else if (op.top() == '-') num.push(a - b);
    else if (op.top() == '*') num.push(a * b);
    else num.push(a / b);
    
    op.pop();
}

int main() {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.size(); i ++ ) { 
        auto c = str[i];
        if (isdigit(c)) {
            int temp = 0, j = i;
            while (j < str.size() && isdigit(str[j]))                   // 扣出数字，加入到栈内
                temp = temp * 10 + str[j ++ ] - '0';
            i = j - 1;
            
            num.push(temp);
        } 
        else if (c == '(') op.push(c);
        else if (c == ')') {
            while (op.top() != '(') eval();                             // 连续操作，直至遇到左括号
            op.pop();                       // 弹出左括号
        }
        else {
            while (op.size() && pr[op.top()] >= pr[c]) eval();          // 若栈顶符号优先级大于当前符号，则操作一下栈顶的两个数
            op.push(c);
        }
    }
    
    while (op.size()) eval();              // 处理栈内剩下的运算符
    
    cout << num.top() << endl;
    
    return 0;  
}