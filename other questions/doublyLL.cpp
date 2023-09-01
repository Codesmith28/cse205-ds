#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct ListNode
{
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode* next, ListNode* prev) : val(x), next(next), prev(prev) {}
};

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* headDummy = head;
    ListNode* tempH = head;
    for (int i = 1; i <= 5; i++)
    {
        ListNode* newNode = new ListNode(i);
        tempH->next = newNode;
        newNode->prev = tempH;
        tempH = tempH->next;
    }

    // insertion:
    ListNode* newNode = new ListNode(6);
    cout << "Where which node you want to insert this: \n";
    int n;
    cin >> n;

    while (headDummy->val != n) {
        headDummy = headDummy->next;
    }
    // head dummy is now at the node where we want to insert

    newNode->next = headDummy->next;
    headDummy->next->prev = newNode;
    headDummy->next = newNode;
    newNode->prev = headDummy;

    ListNode* tail = tempH;
    // iterate from front:
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;

    // iterate from back:
    while (tail != NULL) {
        cout << tail->val << " <- ";
        tail = tail->prev;
    }
    cout << "NULL" << endl;

    return 0;
}