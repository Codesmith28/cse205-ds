#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0); // Initialize with a value
        ListNode* curr = ans;

        int a, b;

        while (list1 != NULL && list2 != NULL) {
            a = list1->val;
            b = list2->val;

            if (a < b) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // Append the remaining nodes from list1 or list2
        if (list1 != NULL) {
            curr->next = list1;
        }
        if (list2 != NULL) {
            curr->next = list2;
        }

        return ans->next; // Sk ip the initial dummy node
    }
};


int main()
{
    Solution sol;
    return 0;
}