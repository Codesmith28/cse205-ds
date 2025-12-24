#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    string processStr(string s) {
        string res;
        for (char c : s) {
            if (c == '*') {
                if (!res.empty( )) {
                    res.pop_back( );
                }
            } else if (c == '#') {
                if (!res.empty( )) {
                    res += res;
                }
            } else if (c == '%') {
                reverse(res.begin( ), res.end( ));
            } else {
                res += c;
            }
        }
        return res;
    }
};

int main( ) {
    vector<string> s = {
        "a#b%*",
        "z*#",
        "p##",
    };
    Solution sol;
    for (auto &str : s) {
        cout << sol.processStr(str) << endl;
    }
    return 0;
}