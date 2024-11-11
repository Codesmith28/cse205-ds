#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    bool isSub(string &source, string &pattern, vector<bool> &removed) {
        int i = 0, j = 0;
        while (i < source.size() && j < pattern.size()) {
            if (source[i] == pattern[j] && !removed[i]) {
                j++;
            }
            i++;
        }
        return j == pattern.size();
    }

    int maxRemovals(string source, string pattern, vector<int> &tar) {
        vector<bool> removed(source.size(), false);
        unordered_map<int, int> memo;

        auto recur = [&](int idx, auto &&recur) {
            if (idx == tar.size()) return 0;
            if (memo.count(idx)) return memo[idx];

            int take = 0;
            removed[tar[idx]] = true;
            if (isSub(source, pattern, removed)) {
                take = 1 + recur(idx + 1, recur);
            }

            removed[tar[idx]] = false;
            int notTake = recur(idx + 1, recur);
            
            return memo[idx] = max(take, notTake);
        };

        recur(0, recur);
        return memo[0];
    }
};

int main() {
    string src;
    string pat;
    vector<int> targetIndices;
    cin >> src >> pat;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        targetIndices.push_back(x);
    }
    Solution sol;
    cout << sol.maxRemovals(src, pat, targetIndices) << endl;
    return 0;
}