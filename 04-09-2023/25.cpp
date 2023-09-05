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

    int getLen(ListNode* head) {

        if (head == NULL) {
            return 0;
        }

        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nexx;

        // apply reversal to the groups:
        int len = getLen(head);

        // base case of the recursion:
        if (len < k or head == NULL) {
            return head;
        }

        // making a copy of k as it will be exhausted
        int kDup = k;

        // reversing a linked list logic but for k nodes only:
        while (curr != NULL and kDup--) {
            nexx = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nexx;
        }

        // for remaining nodes call the recursion:
        if (head != NULL) {
            // recursion will apply the reversal for the next batch of k in the LL
            head->next = reverseKGroup(nexx, k);
        }

        // if our head is exhausted then it means we have completed the list and hence we return prev:
        return prev;
    }
};

int main()
{
    Solution sol;
    return 0;
}