#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // make 2 linked lists such that:
        //  first one contains all the elements smaller than x:
        //  second one contains all the elements greater than or equal to x:

        ListNode *smaller = new ListNode(0);
        ListNode *greater = new ListNode(0);

        ListNode *smallerHead = smaller;
        ListNode *greaterHead = greater;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                smaller->next = head;
                smaller = smaller->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr;
        smaller->next = greaterHead->next;

        return smallerHead->next;
    }
};

int main()
{
    Solution s;
    return 0;
}