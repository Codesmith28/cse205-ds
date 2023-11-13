#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* f, * s, * pre;

    // inorder:
    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);

        if (!f and root->val < pre->val) f = pre;
        if (f and root->val < pre->val) s = root;
        pre = root;

        dfs(root->right);
    }

    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);
        dfs(root);
        swap(f->val, s->val);
    }
};

int main() {

    return 0;
}