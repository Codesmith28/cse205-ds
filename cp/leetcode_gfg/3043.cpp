#include <bits/stdc++.h>
#include <string>
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

bool search(TrieNode *root, string key) {
    TrieNode *node = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!node->child[idx]) return false;
        node = node->child[idx];
    }
    return node->isEnd;
}

bool startsWith(TrieNode *root, string pref) {
    TrieNode *node = root;
    for (char c : pref) {
        int idx = c - 'a';
        if (!node->child[idx]) return false;
        node = node->child[idx];
    }
    return true;
}

class Solution {
  public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        TrieNode *root = new TrieNode();
        for (auto it : arr1) insert(root, to_string(it));

        // find te longest common prefix for arr2
        int res = 0;
        for (auto it : arr2) {
            string s = to_string(it);
            int n = s.size();
            int i = 0;
            TrieNode *node = root;
            while (i < n && node->child[s[i] - '0']) {
                node = node->child[s[i] - '0'];
                i++;
            }
            res += i;
        }

        return res;
    }
};

int main() {
    return 0;
}