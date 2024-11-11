#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void solve() {
    int n;
    cin >> n;

    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    for (int i = 2; i <= n; i++) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    temp->next = head;

    for (int i = 0; i < n; i++) {
        cout << head->next->val << " ";
        head->next = head->next->next;
        head = head->next;
    }

    cout << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
