#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();
        ListNode* temp = answer; //points to the answer
        int carryOver = 0;

        while (l1 != NULL or l2 != NULL or carryOver) {
            int digit = 0;

            if (l1 != NULL) {
                digit += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                digit += l2->val;
                l2 = l2->next;
            }

            digit += carryOver;
            carryOver = digit / 10;
            ListNode* nodeNew = new ListNode(digit % 10);
            temp->next = nodeNew;
            temp = temp->next;
        }
        return answer->next;
    }
};

int main()
{
    Solution sol;
    return 0;
}