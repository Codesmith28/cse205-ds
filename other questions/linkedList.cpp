#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{
    ListNode *head = new ListNode(18);
    head->next = new ListNode(36);
    head->next->next = new ListNode(13);

    // // print the linked linst:
    // while (head != NULL)
    // {
    //     cout << head->val << " ";
    //     head = head->next;
    // }

    ListNode *ins = new ListNode(96);

    // insert between 18 and 36:
    ListNode *newNode = new ListNode(96);

    newNode->next = head->next;
    head->next = newNode;

    cout << "\nAfter insertion: ";
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}