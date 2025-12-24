#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TrieNode {
    TrieNode *child[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

void insert(TrieNode *root, string key) {
    TrieNode *node = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!node->child[idx]) node->child[idx] = new TrieNode();
        node = node->child[idx];
    }
    node->isEnd = true;
}

class Solution {
  public:
    int minExtraChar(string s, vector<string> &dict) {
        int n = s.size();
        unordered_map<int, int> memo;

        TrieNode *root = new TrieNode();
        for (string word : dict) insert(root, word);

        auto dp = [&](int idx, auto &&dp) -> int {
            if (idx == n) return 0;
            if (memo.count(idx)) return memo[idx];

            int res = dp(idx + 1, dp) + 1;
            TrieNode *node = root;

            for (int i = idx; i < n; i++) {
                char c = s[i];
                if (!node->child[c - 'a']) break;
                node = node->child[c - 'a'];
                if (node->isEnd) res = min(res, dp(i + 1, dp));
            }

            return memo[idx] = res;
        };

        return dp(0, dp);
    }
};

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    Solution sol;
    cout << sol.minExtraChar(s, words) << endl;
    return 0;
}