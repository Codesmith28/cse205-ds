#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class TrieNode {
  public:
    unordered_map<string, TrieNode *> children;
    bool isEndOfFolder;

    TrieNode( ) : isEndOfFolder(false) {
    }
};

class Solution {
  private:
    TrieNode *root;

    void insert(const string &folder) {
        TrieNode *node = root;
        stringstream ss(folder);
        string part;

        while (getline(ss, part, '/')) {
            if (part.empty( )) continue;
            if (node->children.find(part) == node->children.end( )) {
                node->children[part] = new TrieNode( );
            }
            node = node->children[part];
        }
        node->isEndOfFolder = true;
    }

    void collectFolders(TrieNode *node, string &currentPath, vector<string> &result) {
        if (node->isEndOfFolder) {
            result.push_back(currentPath);
            return;
        }

        for (const auto &child : node->children) {
            string newPath = currentPath + "/" + child.first;
            collectFolders(child.second, newPath, result);
        }
    }

  public:
    vector<string> removeSubfolders(vector<string> &folder) {
        root = new TrieNode( );

        // Insert all folders into the trie
        for (const string &f : folder) {
            insert(f);
        }

        // Collect non-subfolder paths
        vector<string> result;
        string currentPath;
        collectFolders(root, currentPath, result);

        return result;
    }
};

int main( ) {
    vector<vector<string>> f = {
        {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"},
        {"/a", "/a/b/c", "/a/b/d"},
        {"/a/b/c", "/a/b/ca", "/a/b/d"}
    };
    Solution s;
    for (auto it : f) {
        vector<string> res = s.removeSubfolders(it);
        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
