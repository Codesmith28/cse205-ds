#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    unordered_map<int, int> mp;
    int idx = 0; // Preorder index

    TreeNode* build(vector<int>& pre, vector<int>& in, int st, int en) {

        if (st > en) {
            return nullptr;
        }

        int root_val = pre[idx];
        TreeNode* root = new TreeNode(root_val);
        idx++;

        int pos = mp[root_val]; // Index of root_val in inorder

        root->left = build(pre, in, st, pos - 1);
        root->right = build(pre, in, pos + 1, en);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};


int main() {

    return 0;
}