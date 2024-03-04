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
    ListNode* detectCycle(ListNode* head) {
        ListNode* dummy = head;
        ListNode* fast = head;

        while (fast != NULL and fast->next != NULL) {
            head = head->next;
            fast = fast->next->next;

            if (head == fast) {
                // cout << head -> val << endl;
                // return head; // or head->next

                while (dummy != head) {
                    head = head->next;
                    dummy = dummy->next;
                }

                return head;
            }
        }

        return NULL;
    }
};

int main()
{
    Solution sol;
    return 0;
}