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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // answer node pointing to the given LL
        ListNode* answer = new ListNode();
        answer->next = head;

        // 2 pointers set at answer node
        ListNode* a = answer;
        ListNode* b = answer;

        // moving the first ptr forward by n nodes
        for (int i = 0; i < n; i++) {
            a = a->next;
        }

        // starting to move 2nd pointer when 1st reaches n
        // this way when 1st reaches NULL 2nd will reach n from end
        // this is made sure as the gap between them remains the same which is = n
        while (a->next != NULL) {
            a = a->next;
            b = b->next;
        }

        b->next = b->next->next;
        return answer->next;
    }
};

int main()
{
    Solution sol;
    return 0;
}