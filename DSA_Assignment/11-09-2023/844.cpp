#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a, b;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                a.push(s[i]);
            }
            else if (!a.empty()) {
                a.pop();
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] != '#') {
                b.push(t[i]);
            }
            else if (!b.empty()) {
                b.pop();
            }
        }

        while (!a.empty() and !b.empty()) {
            if (a.top() != b.top()) {
                return false;
            }

            a.pop(); b.pop();
        }

        return a.empty() and b.empty();
    }
};


int main()
{
    Solution sol;
    string s = "ab#c";
    string t = "ad#c";

    cout << sol.backspaceCompare(s, t) << endl;

    return 0;
}