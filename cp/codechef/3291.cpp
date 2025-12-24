#include <bits/stdc++.h>
#include <climits>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TrieNode {
    TrieNode *child[26];
    bool isEnd; // word ended

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

void insert(TrieNode *root, string key) {
    TrieNode *temp = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!temp->child[idx]) {
            temp->child[idx] = new TrieNode();
        }
        temp = temp->child[idx];
    }
    temp->isEnd = true;
}

bool search(TrieNode *root, string key) {
    TrieNode *temp = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!temp->child[idx]) {
            return false;
        }
        temp = temp->child[idx];
    }
    return temp->isEnd;
}

class Solution {
  public:
    int minValidStrings(vector<string> &words, string target) {
        TrieNode trie;
        for (string word : words) {
            insert(&trie, word);
        }

        int n = target.size();
        int res = INT_MAX;

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        auto dfs = [&](int idx, auto &&dfs) -> int {
            if (dp[idx] != INT_MIN) return dp[idx];

            TrieNode *temp = &trie;
            int res = INT_MAX;

            for (int j = idx; j < n; j++) {
                int i = target[j] - 'a';
                if (temp->child[i] == NULL) break;
                temp = temp->child[i];

                if (temp->isEnd) {
                    int t = dfs(j + 1, dfs);
                    if (t != INT_MAX) res = min(res, t + 1);
                }
            }

            return dp[idx] = res;
        };

        int ans = dfs(0, dfs);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    return 0;
}