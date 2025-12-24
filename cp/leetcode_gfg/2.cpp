#include <bits/stdc++.h>
#include <string>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

using namespace std;

#define ll long long

class Solution {
  public:
    int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<ll> fq(26, 0);
        for (char c : s) fq[c - 'a']++;

        while (t--) {
            vector<ll> new_fq(26, 0);

            for (int i = 0; i < 26; ++i) {
                if (fq[i] == 0) continue;
                if (i == 25) {
                    new_fq[0] = (new_fq[0] + fq[i]) % mod;
                    new_fq[1] = (new_fq[1] + fq[i]) % mod;
                } else {
                    new_fq[i + 1] = (new_fq[i + 1] + fq[i]) % mod;
                }
            }
            fq = new_fq;
        }

        ll ans = 0;
        for (ll count : fq) {
            ans = (ans + count) % mod;
        }

        return ans;
    }
};

int main( ) {
    Solution sol;
    vector<string> s = {"abcyy", "azbk", "evxnefooctnzysptfwzmkfxzeewqtgdxmmfhnvcebgakpvegedpyqsothvh"};
    vector<int> t = {2, 1, 7177};
    for (int i = 0; i < s.size( ); i++) {
        cout << sol.lengthAfterTransformations(s[i], t[i]) << endl;
    }
    return 0;
}