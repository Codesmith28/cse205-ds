#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TrieNode {
    TrieNode *child[26];
    bool isEnd; // word ended

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

void insert(TrieNode *root, string key) {
    TrieNode *temp = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!temp->child[idx]) temp->child[idx] = new TrieNode();
        temp = temp->child[idx];
    }
    temp->isEnd = true;
}

bool search(TrieNode *root, string key) {
    TrieNode *temp = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!temp->child[idx]) return false;
        temp = temp->child[idx];
    }
    return temp->isEnd;
}

class Solution {
  public:
    int minValidStrings(vector<string> &words, string target) {
        TrieNode *root = new TrieNode();
        for (auto it : words) insert(root, it);

        int n = target.size();
        vector<int> dp(n, -1);

        auto dfs = [&](int i, auto &&dfs) -> int {
            if (i == n) return 0;
            if (dp[i] != -1) return dp[i];

            TrieNode *curr = root;
            int res = INT_MAX;

            string s;
            for (int j = i; j < n; j++) {
                s += target[j];
                if (!search(root, s)) break;
                int nxt = dfs(j + 1, dfs);
                if (nxt != INT_MAX) res = min(nxt + 1, res);
            }

            return dp[i] = res;
        };

        int ans = dfs(0, dfs);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    return 0;
}