#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main()
{
    ListNode* head = new ListNode(18);
    head->next = new ListNode(36);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(42);
    // list right now: 18 -> 36 -> 13 -> 42

    head->next = head->next->next;

    // print the linked linst:
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL \n";

    return 0;
}