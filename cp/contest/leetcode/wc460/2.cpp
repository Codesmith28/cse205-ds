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
    long long numOfSubsequences(string s) {
        using ll = long long;
        int n = s.size( );

        vector<ll> pref_l(n + 1), pref_lc(n + 1);
        ll cnt_l = 0, cnt_lc = 0, total = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L')
                cnt_l++;
            else if (s[i] == 'C')
                cnt_lc += cnt_l;
            else if (s[i] == 'T')
                total += cnt_lc;
            pref_l[i + 1] = cnt_l;
            pref_lc[i + 1] = cnt_lc;
        }

        vector<ll> suf_c(n + 1), suf_ct(n + 1), suf_t(n + 1);
        ll cnt_c = 0, cnt_ct = 0, cnt_t = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'T')
                cnt_t++;
            else if (s[i] == 'C') {
                cnt_ct += cnt_t;
                cnt_c++;
            }
            suf_c[i] = cnt_c;
            suf_t[i] = cnt_t;
            suf_ct[i] = cnt_ct;
        }

        ll gain = 0;
        for (int i = 0; i <= n; ++i) {
            gain = max(gain, suf_ct[i]);            // insert L
            gain = max(gain, pref_l[i] * suf_t[i]); // insert C
            gain = max(gain, pref_lc[i]);           // insert T
        }

        return total + gain;
    }
};

int main( ) {
    vector<string> testCases = {"LMCT", "LCCT", "L", "LT", "LCTKLCLT"};
    Solution sol;
    for (auto &testCase : testCases) {
        cout << sol.numOfSubsequences(testCase) << endl;
    }
    return 0;
}