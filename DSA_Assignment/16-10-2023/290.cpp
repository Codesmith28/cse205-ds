#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    bool wordPattern(string p, string s) {
        string temp;

        vector<string> st;
        vector<char> pt;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                st.push_back(temp);
                temp = "";
            }
            else {
                temp += s[i];
            }
        } st.push_back(temp);

        for (int i = 0; i < p.size(); i++) {
            pt.push_back(p[i]);
        }

        if (pt.size() != st.size()) {
            return false;
        }

        map<char, string> mp;
        map<string, char> mpr;

        for (int i = 0; i < pt.size(); i++) {
            string word = st[i];
            char letter = pt[i];

            if (mp.find(pt[i]) == mp.end()) {
                mp[pt[i]] = st[i];
            }

            if (mpr.find(st[i]) == mpr.end()) {
                mpr[st[i]] = pt[i];
            }

            if (mp[pt[i]] != st[i] or mpr[st[i]] != pt[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";

    cout << sol.wordPattern(pattern, s) << endl;
    
    return 0;
}