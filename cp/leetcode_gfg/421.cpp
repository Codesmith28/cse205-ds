#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TrieNode {
    TrieNode *child[2];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 2; i++) child[i] = NULL;
    }
};

void insert(TrieNode *root, string key) {
    TrieNode *node = root;
    for (char c : key) {
        int idx = c - '0';
        if (!node->child[idx]) node->child[idx] = new TrieNode();
        node = node->child[idx];
    }
    node->isEnd = true;
}

int search(TrieNode *root, string key) {
    TrieNode *node = root;
    int res = 0;

    for (char c : key) {
        int idx = c - '0';
        int oppo = 1 - idx;
        if (node->child[oppo]) {
            res = (res << 1) | 1;
            node = node->child[oppo];
        } else {
            res = (res << 1);
            node = node->child[idx];
        }
    }
    return res;
}

class Solution {
  public:
    int getMsb(int n) {
        int msb = 0;
        while (n) {
            msb++;
            n >>= 1;
        }
        return msb;
    }

    int findMaximumXOR(vector<int> &nums) {
        int mx = *max_element(begin(nums), end(nums));
        int msb = getMsb(mx);

        vector<string> bins;
        for (auto it : nums) bins.push_back(bitset<32>(it).to_string().substr(32 - msb));

        TrieNode *root = new TrieNode();
        for (string &s : bins) insert(root, s);

        int res = 0;
        for (string &s : bins) {
            int xorI = search(root, s);
            res = max(res, xorI);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> nums = {
        {0},
    };

    Solution s;
    for (auto it : nums) cout << s.findMaximumXOR(it) << endl;

    return 0;
}