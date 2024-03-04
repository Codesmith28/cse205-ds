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

    // left most -> smallest
    // right most -> largest

    // inorder dfs:
    void dfs(TreeNode* root, int& k, int& ans) {
        if (!root) return;

        dfs(root->left, k, ans);
        if (--k == 0) ans = root->val;
        dfs(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        dfs(root, k, ans);
        return ans;
    }
};

int main() {

    return 0;
}