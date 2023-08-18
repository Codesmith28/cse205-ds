#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    void recursion(vector<string> &ans, int l, int r, string s, int n)
    {

        // for n parenthesis:
        // total length would be of 2n
        if (s.length() == n * 2)
        {
            ans.push_back(s);
            return;
        }

        // l is the number of open parenthesis
        // r is the number of closed parenthesis
        // each entry should have n open and n closed parenthesis

        if (l < n)
        {
            recursion(ans, l + 1, r, s + "(", n);
        }

        if (r < l)
        {
            recursion(ans, l, r + 1, s + ")", n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        recursion(ans, 0, 0, "", n);
        return ans;
    }
};

int main()
{
    Solution sol;

    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);

    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}