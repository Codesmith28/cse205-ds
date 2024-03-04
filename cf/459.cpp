#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string duet = s + s;
        // remove first and last character:
        duet = duet.substr(1, duet.length() - 2);

        if (duet.find(s) != -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.repeatedSubstringPattern("abab") << endl;
    cout << s.repeatedSubstringPattern("aba") << endl;
    cout << s.repeatedSubstringPattern("abcabcabcabc") << endl;
    return 0;
}