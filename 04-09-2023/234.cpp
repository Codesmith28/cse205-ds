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
    bool isPalindrome(ListNode* head) {
        string ll = "";

        while (head != NULL) {
            // convert the ll into a string
            ll += to_string(head->val);
            head = head->next;
        }

        // reverse and check:
        string rev = ll;
        reverse(ll.begin(), ll.end());
        return (rev == ll);
    }
};

int main()
{
    Solution sol;
    return 0;
}