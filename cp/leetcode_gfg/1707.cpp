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

    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int mx = nums[n - 1];
        int msb = getMsb(mx);

        // vector<pair<int, string>> bins;
        // for (auto it : nums) bins.push_back({it, bitset<32>(it).to_string().substr(32 - msb)});
        map<int, string> bins;
        for (auto it : nums) bins[it] = bitset<32>(it).to_string().substr(32 - msb);

        TrieNode *root = new TrieNode();
        for (auto [num, s] : bins) insert(root, s);

        vector<int> res;
        for (auto it : queries) {
            int x = it[0], m = it[1];
            string currStr = bins[x];
            int curr = INT_MIN;

            for (int i = 0; i < msb; i++) {
                if (m & (1 << (msb - i - 1))) {
                    if (currStr[i] == '0') {
                        currStr[i] = '1';
                    } else {
                        currStr[i] = '0';
                    }
                }
            }

            curr = search(root, currStr);
            res.push_back(curr);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> nums = {
        {0, 1, 2, 3, 4},
        {5, 2, 4, 6, 6, 3},
    };

    vector<vector<vector<int>>> queries = {
        {{3, 1},  {1, 3}, {5, 6}},
        {{12, 4}, {8, 1}, {6, 3}},
    };

    Solution s;
    for (int i = 0; i < nums.size(); i++) {
        for (auto it : s.maximizeXor(nums[i], queries[i])) cout << it << " ";
        cout << endl;
    }

    return 0;
}