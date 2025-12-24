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
    char processStr(string s, long long k) {
        using ll = long long;
        int n = s.size( );
        vector<ll> len(n); // len after i-th op

        ll curr = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '*') {
                if (curr > 0) curr--;
            } else if (c == '#') {
                curr *= 2;
            } else if (c == '%') {
            } else {
                curr++;
            }
            len[i] = curr;
        }

        if (k >= curr) return '.';

        for (int i = n - 1; i >= 0; i--) { // ops
            char c = s[i];
            ll prev = (i > 0 ? len[i - 1] : 0);

            if (c == '*') {
                if (prev < len[i]) {
                    if (k == prev) return '.';
                }
            } else if (c == '#') {
                if (k >= prev) {
                    k -= prev;
                }
            } else if (c == '%') {
                k = len[i] - 1 - k;
            } else {
                if (len[i] - prev == 1) {
                    if (k == len[i] - 1) return c;
                }
            }
        }

        return '.';
    }
};

int main( ) {
    vector<string> s = {
        "a#b%*",
        "cd%#*#",
        "z*#",
    };
    vector<long long> k = {1, 3, 0};
    Solution sol;
    for (int i = 0; i < s.size( ); i++) cout << sol.processStr(s[i], k[i]) << endl;
    return 0;
}