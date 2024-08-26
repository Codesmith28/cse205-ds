#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    string convertToTitle(int n)
    {

        string ans = "";
        while (n > 0)
        {
            n--; // it just works -> due to 1 based indexing
            ans += char('A' + ((n) % 26));
            n /= 26;
        }

        // as answer was coming in reverse:
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.convertToTitle(701) << endl;
    return 0;
}