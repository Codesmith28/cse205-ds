#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TrieNode {
    map<string, TrieNode *> child;
    bool is_end;
    TrieNode( ) {
        is_end = false;
    }

    void insert(TrieNode *root, string &path) {
        TrieNode *node = root;
        string curr = "";
        for (char c : path) {
            if (c == '/') {
                if (!curr.empty( )) {
                    if (node->child.find(curr) == node->child.end( )) {
                        node->child[curr] = new TrieNode( );
                    }
                    node = node->child[curr];
                    curr = "";
                }
            } else {
                curr += c;
            }
        }
        if (!curr.empty( )) {
            if (node->child.find(curr) == node->child.end( )) {
                node->child[curr] = new TrieNode( );
            }
            node = node->child[curr];
        }
        node->is_end = true;
    }

    void collect(TrieNode *root, string &path, vector<string> &res) {
        if (root->is_end) {
            res.push_back(path);
            return;
        }
        for (auto [dir, node] : root->child) {
            string curr = path + "/" + dir;
            collect(node, curr, res);
        }
    }
};

class Solution {
  public:
    vector<string> removeSubfolders(vector<string> &folder) {
        TrieNode *root = new TrieNode( );
        for (auto it : folder) root->insert(root, it);
        vector<string> res;
        string curr = "";
        root->collect(root, curr, res);
        return res;
    }
};

int main( ) {
    vector<vector<string>> testCases = {
        {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"},
        {"/a", "/a/b/c", "/a/b/d"},
        {"/a/b/c", "/a/b/ca", "/a/b/d"},
    };
    Solution sol;
    for (auto &testCase : testCases) {
        auto ans = sol.removeSubfolders(testCase);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
