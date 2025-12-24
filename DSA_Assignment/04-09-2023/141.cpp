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
    bool hasCycle(ListNode* head) {

        if (head == NULL) {
            return false;
        }

        ListNode* fast = head;
        while (fast->next != NULL and fast->next->next != NULL) {
            fast = fast->next->next;
            head = head->next;

            if (head == fast) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    return 0;
}