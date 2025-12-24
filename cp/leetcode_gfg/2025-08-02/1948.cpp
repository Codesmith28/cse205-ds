#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    string dir;
    bool remove;
    map<string, TrieNode *> child;

    TrieNode(string _dir) {
        dir = _dir;
        remove = false;
    }
};

/// populate trie
void insert(TrieNode *root, vector<string> &path) {
    TrieNode *node = root;
    for (auto it : path) {
        if (!node->child.count(it)) {
            node->child[it] = new TrieNode(it);
        }
        node = node->child[it];
    }
}

/// serialize and deduplicate directories
string serialize_dedeup(TrieNode *root, map<string, TrieNode *> &vis) {
    string sub_dir;
    for (auto [dir, node] : root->child) sub_dir += serialize_dedeup(node, vis);
    if (sub_dir.size( ) > 0) {
        if (vis.count(sub_dir)) { // found already
            TrieNode *target = vis[sub_dir];
            // remove both
            target->remove = true;
            root->remove = true;
        } else { // not found
            vis[sub_dir] = root;
        }
    }
    return "[" + root->dir + sub_dir + "]";
}

/// cleanup
void cleanup(TrieNode *root, vector<string> &curr, vector<vector<string>> &res) {
    if (root->remove) return;

    curr.push_back(root->dir);
    res.push_back(curr);
    for (auto [sub_dir, node] : root->child) {
        cleanup(node, curr, res);
    }
    curr.pop_back( );
}

class Solution {
  public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths) {
        /// populate trie
        TrieNode *root = new TrieNode("/");
        for (auto it : paths) insert(root, it);

        /// serialize and deduplicate directories
        map<string, TrieNode *> vis;
        serialize_dedeup(root, vis);

        /// cleanup
        vector<vector<string>> res;
        vector<string> curr;
        cleanup(root, curr, res);

        return res;
    }
};

int main( ) {
    Solution sol;
    vector<vector<vector<string>>> paths_list = {
        {{"a"}, {"c"}, {"d"}, {"a", "b"}, {"c", "b"}, {"d", "a"}},
        {{"a"}, {"c"}, {"a", "b"}, {"c", "b"}, {"a", "b", "x"}, {"a", "b", "x", "y"}, {"w"}, {"w", "y"}},
        {{"a", "b"}, {"c", "d"}, {"c"}, {"a"}}
    };

    for (auto &paths : paths_list) {
        vector<vector<string>> result = sol.deleteDuplicateFolder(paths);
        for (const auto &res : result) {
            for (const auto &folder : res) {
                cout << folder << " ";
            }
            cout << endl;
        }
        cout << "-----\n";
    }

    return 0;
}
