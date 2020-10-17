#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A, int b) {
    vector<int> C;
    
    int t = 0;
    for (int i = 0; i < A.size() || t; ++i) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

vector<int> mul1(vector<int> &A, vector<int> &B) {
    vector<int> C(A.size() + B.size());

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            C[i + j] += A[i] * B[j];

    for (int i = 0, t = 0; i < C.size() || t; i++) {
        t += C[i];
        if (i >= C.size()) C.push_back(t % 10);
        else C[i] = t % 10;

        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {
    /*
    string a;
    int b;
    vector<int> A;
    
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    */


    string a, b;
    vector<int> A, B;
    
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0');
    
    auto C = mul1(A, B);
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];

    return 0;
}