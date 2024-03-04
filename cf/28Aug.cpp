#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main() {

    ListNode* head = new ListNode();
    head->next = new ListNode(11);
    head->next->next = new ListNode(52);
    head->next->next->next = new ListNode(18);

    // duplicate node at head for iteration:
    ListNode* dummy = head;

    // finding the key element in the linkedlist:
    cout << "Enter key: \n";
    int key;
    cin >> key;

    while (head->next->val != key) {
        head = head->next;
    }

    // right now out head points to key node: head->next == key 
    ListNode* bet = new ListNode(99);
    bet->next = head->next;
    head->next = bet;

    // printh the entire linkedlist:
    while (dummy != NULL) {
        cout << dummy->val << " -> ";
        dummy = dummy->next;
    }
    cout << "NULL \n";

    return 0;
}