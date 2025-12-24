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
    set<string> valid = {"electronics", "grocery", "pharmacy", "restaurant"};
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive) {
        map<string, vector<string>> grp;
        int n = code.size( );

        for (int i = 0; i < n; ++i) {
            string c = code[i], b = businessLine[i];
            bool a = isActive[i];

            if (c.empty( )) continue;
            bool valid_code = true;
            for (char ch : c) {
                if (!isalnum(ch) && ch != '_') {
                    valid_code = false;
                    break;
                }
            }

            if (!valid_code) continue;
            if (!valid.count(b)) continue;
            if (!a) continue;
            grp[b].push_back(c);
        }

        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        vector<string> result;
        for (string cat : order) {
            sort(grp[cat].begin( ), grp[cat].end( ));
            for (string &coupon : grp[cat]) {
                result.push_back(coupon);
            }
        }

        return result;
    }
};

int main( ) {
    vector<vector<string>> code = {
        {"SAVE20", "", "PHARMA5", "SAVE@20"},
        {"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"}
    };
    vector<vector<string>> businessLine = {
        {"restaurant", "grocery", "pharmacy", "restaurant"},
        {"grocery", "electronics", "invalid"},
    };
    vector<vector<bool>> isActive = {
        {true, true, true, true},
        {false, true, true},
        {true, true, false}
    };
    Solution sol;
    for (int i = 0; i < code.size( ); ++i) {
        vector<string> result = sol.validateCoupons(code[i], businessLine[i], isActive[i]);
        for (const string &res : result) {
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}
