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

    void rec(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        rec(root->left, ans);
        ans.push_back(root->val);
        rec(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        rec(root, ans);
        return ans;
    }
};

int main() {
    Solution s;
    return 0;
}