#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // (since curr node needs to be deleted)
        // replacing the value of curr node with the val of next node
        node->val = node->next->val;

        // skipping the next node:
        node->next = node->next->next;
    }
};

int main()
{
    return 0;
}