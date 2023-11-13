#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    // BST: left < right
    // postorder dfs
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = root->val;
        int b = p->val;
        int c = q->val;

        if (a > b and a > c) return lowestCommonAncestor(root->left, p, q);
        else if (a < b and a < c) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

int main() {

    return 0;
}