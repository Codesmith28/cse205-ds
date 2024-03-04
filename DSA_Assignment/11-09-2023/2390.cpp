#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    string removeStars(string s) {

        stack<char> b;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                b.push(s[i]);
            }
            else if (!b.empty()) {
                b.pop();
            }
        }

        string ans = "";

        while (!b.empty()) {
            ans += b.top();
            b.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "leet**cod*e";

    cout << sol.removeStars(s) << endl;
    return 0;
}