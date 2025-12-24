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
    ListNode* middleNode(ListNode* head) {
        // move one at normal speed
        // move 2nd one at 2x speed

        ListNode* dou = head;

        while (dou->next != nullptr) {
            head = head->next;
            dou = dou->next->next;

            if (dou == nullptr) {
                break;
            }
        }

        return head;
    }
};

int main()
{
    Solution sol;
    return 0;
}