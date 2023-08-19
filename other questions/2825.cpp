#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {

        int a = str1.size();
        int b = str2.size();

        // code it so that it has to be the same index:
        int i = 0;
        for (auto it : str2)
        {
            char x;
            (it == 'a') ? x = 'z' : x = it--;

            // neither present normally nor in prevly:
            while (i < a and str1[i] != it and str1[i] != x)
            {
                i++;
            }

            // whole iteration completed and could not find one:
            if (i >= a)
            {
                return false;
            }

            // if in case found one then leave this char from str1
            i++;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    string str1 = "abc";
    string str2 = "ahbgdc";

    cout << sol.canMakeSubsequence(str1, str2) << endl;

    return 0;
}