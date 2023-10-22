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
    int calcH(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lHeight = calcH(root->left);
        int rHeight = calcH(root->right);

        return max(lHeight, rHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        // calculating left and right heights:
        int lHeight = calcH(root->left);
        int rHeight = calcH(root->right);

        // via root node:
        int currDim = lHeight + rHeight;

        // without root node:
        int lDim = diameterOfBinaryTree(root->left);
        int rDim = diameterOfBinaryTree(root->right);

        return max({ lDim, rDim, currDim });
    }
};


int main() {
    return 0;
}