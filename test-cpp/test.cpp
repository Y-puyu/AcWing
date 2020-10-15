#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str= "1234 567890";
    for (int i = 1; i < str.size(); ++i) {
        cout << "str   " << str << endl;
        str.substr(0, i);
        cout << "str   " << str << endl;
    }
    return 0;
}