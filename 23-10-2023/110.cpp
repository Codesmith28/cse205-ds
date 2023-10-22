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

        return max(calcH(root->left), calcH(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if (!root) {
            return true;
        }

        if (!isBalanced(root->left)) {
            return false;
        }
        if (!isBalanced(root->right)) {
            return false;
        }

        int lh = calcH(root->left);
        int rh = calcH(root->right);

        if (abs(lh - rh) <= 1) {
            return true;
        }

        return false;
    }
};

int main() {
    return 0;
}