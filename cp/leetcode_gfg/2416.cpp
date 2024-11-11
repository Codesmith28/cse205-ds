#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TrieNode {
    TrieNode *child[26];
    bool isEnd;
    int count = 0;
    TrieNode() {
        isEnd = false;
        count = 0;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

void insert(TrieNode *root, string key) {
    TrieNode *node = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!node->child[idx]) node->child[idx] = new TrieNode();
        node = node->child[idx];
        node->count++;
    }
    node->isEnd = true;
}

int startWith(TrieNode *root, string pref) {
    int score = 0;
    TrieNode *node = root;
    for (char c : pref) {
        int idx = c - 'a';
        if (!node->child[idx]) break;
        node = node->child[idx];
        score += node->count;
    }
    return score;
}

class Solution {
  public:
    vector<int> sumPrefixScores(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (auto it : words) insert(root, it);

        vector<int> res;
        for (auto it : words) res.push_back(startWith(root, it));
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    Solution s;
    vector<int> res = s.sumPrefixScores(words);
    for (auto it : res) cout << it << " ";
    return 0;
}
