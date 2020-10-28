#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode (int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void my_memcpy(void *dst, const void *src, int size) {
    char *d = (char*)dst;
    const char *s = (char*)src;
    while (size--) *d++ = *s++;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5];

    my_memcpy(arr2, arr1, 20);

    for (int i = 0; i < 5; ++i) {
        cout << arr2[i] << ' ';
    }
    cout << endl;




    return 0;
}