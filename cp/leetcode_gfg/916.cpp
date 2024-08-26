#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:

    bool checker(string word, vector<string>& list) {
        bool flag = true;

        // words in the list should be subset of word
        for (auto it : list) {
            unordered_map<char, int> mp;
            for (auto ch : word) {
                mp[ch]++;
            }

            for (auto ch : it) {
                mp[ch]--;
            }

            for (auto it : mp) {
                // reducing more than what was present hence not a subset
                if (it.second < 0) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                break;
            }
        }

        return flag;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        for (auto word : words1) {
            if (checker(word, words2)) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words1 = { "amazon","apple","facebook","google","leetcode" };
    vector<string> words2 = { "le","eo" };

    vector<string> ans = s.wordSubsets(words1, words2);

    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}