#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        string ac = "";
        for (auto it : words)
        {
            ac += it[0];
        }

        return (s == ac);
    }
};

int main()
{
    Solution sol;

    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    string s = "Alaska";

    cout << sol.isAcronym(words, s) << endl;
    return 0;
}