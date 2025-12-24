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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_map<ListNode*, bool> map;

        ListNode* curr = headA;
        // marking all nodes to be visited
        while (curr != NULL) {
            map[curr] = true;
            curr = curr->next;
        }

        curr = headB;
        while (curr != NULL) {
            if (map[curr] == true) {
                return curr;
            }
            curr = curr->next;
        }

        return NULL;
    }
};

int main()
{
    Solution sol;
    return 0;
}