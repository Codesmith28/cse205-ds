#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
  public:
    TreeNode *lca(TreeNode *node, int v1, int v2) {
        if (!node) return NULL;
        if (node->val == v1 || node->val == v2) return node;
        TreeNode *left = lca(node->left, v1, v2);
        TreeNode *right = lca(node->right, v1, v2);
        if (!left)
            return right;
        else if (!right)
            return left;
        else
            return node;
    }

    bool pathFinder(TreeNode *node, int tar, string &path) {
        if (!node) return false;
        if (node->val == tar) return true;

        path += 'L';
        if (pathFinder(node->left, tar, path)) return true;
        path.pop_back();

        path += 'R';
        if (pathFinder(node->right, tar, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode *root, int st, int en) {
        TreeNode *lcaNode = lca(root, st, en);
        string start, dest;

        pathFinder(lcaNode, st, start);
        pathFinder(lcaNode, en, dest);

        string ans;
        ans.append(start.length(), 'U');
        ans.append(dest);
        return ans;
    }
};

int main() {
    return 0;
}
