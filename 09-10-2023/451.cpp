#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char, int> f;
        for (auto it : s) {
            f[it]++;
        }

        vector<pair<int, char>> fq;
        for (auto it : f) {
            fq.push_back({ it.second, it.first });
        }

        sort(rbegin(fq), rend(fq));

        string ans = "";

        for (auto it : fq) {
            for (int i = 0; i < it.first; i++) {
                ans += it.second;
            }
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl;

    return 0;
}