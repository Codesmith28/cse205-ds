#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* ans = new ListNode(0); // Dummy node to simplify insertion at the beginning
        ans->next = head;

        ListNode* current = head;
        ListNode* prev = nullptr;

        while (current and current->next) {
            if (current->val <= current->next->val) {
                // If the current node is in the correct position, move to the next node
                current = current->next;
            }
            else {
                // Otherwise, we need to insert current->next into its correct position
                ListNode* temp = ans;
                while (temp->next->val < current->next->val) {
                    temp = temp->next;
                }
                // Perform the insertion
                ListNode* tempNext = temp->next;
                temp->next = current->next;
                current->next = current->next->next;
                temp->next->next = tempNext;
            }
        }

        return ans->next;
    }
};

int main()
{
    Solution sol;
    return 0;
}