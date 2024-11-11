#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
  public:
    int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t, vector<int> &nums) {
        vector<ll> fq(26, 0);
        for (char c : s) fq[c - 'a']++;

        ll ans = 0;

        while (t--) {
            vector<ll> new_fq(26, 0);
            for (int i = 0; i < 26; i++) {
                if (fq[i] > 0) {
                    for (int j = 0; j < nums[i]; j++) {
                        int new_idx = (i + j + 1) % 26;
                        new_fq[new_idx] = (new_fq[new_idx] + fq[i]) % mod;
                    }
                }
            }
            fq = new_fq;
        }

        for (int i = 0; i < 26; i++) ans = (ans + fq[i]) % mod;
        return ans;
    }
};

int main( ) {
    string s;
    cin >> s;
    int t;
    cin >> t;
    vector<int> nums(26);
    for (int i = 0; i < 26; i++) cin >> nums[i];
    Solution sol;
    cout << sol.lengthAfterTransformations(s, t, nums) << endl;
    return 0;
}
