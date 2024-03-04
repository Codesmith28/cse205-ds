#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for (char it : s) {
            mp[it]++;
        }

        string ans = "";

        for (char x : order) {
            if (mp.find(x) != mp.end()) {
                int fq = mp[x];
                while (fq--) {
                    ans.push_back(x);
                }
                mp.erase(x);
            }
        }

        for (auto it : mp) {
            while (it.second--) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    string order = "cba";
    string s = "abcd";

    cout << sol.customSortString(order, s) << endl;
    return 0;
}