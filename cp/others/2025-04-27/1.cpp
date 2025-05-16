#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int longestPalindrome(string s, string t) {
        int n = s.size( );
        int m = t.size( );

        vector<string> subs, subt;

        subs.push_back("");
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                subs.push_back(s.substr(i, j - i));
            }
        }

        subt.push_back("");
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j <= m; j++) {
                subt.push_back(t.substr(i, j - i));
            }
        }

        int mx = 0;
        string final = "";

        for (auto it : subs) {
            for (auto jt : subt) {
                string concat = it + jt;
                string rev = concat;
                reverse(rev.begin( ), rev.end( ));
                if (concat == rev) {
                    mx = max(mx, (int)concat.size( ));
                    dbg(concat);
                }
            }
        }

        cout << "Final: " << final << endl;
        return mx;
    }
};

int main( ) {
    Solution sol;
    vector<string> s = {"a", "abc", "b", "abcde", "p"};
    vector<string> t = {"a", "def", "aaaa", "ecdba", "krykpr"};
    for (int i = 0; i < s.size( ); i++) {
        cout << sol.longestPalindrome(s[i], t[i]) << endl;
    }
    return 0;
}
