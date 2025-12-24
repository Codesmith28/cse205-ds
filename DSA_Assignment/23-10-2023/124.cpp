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

    /* we will need the following values:
    node val
    mx path sum at left + node val
    mx path sum at right + node val
    mx path sum at right + mx path sum at left + node val
    */

    bool isLeaf(TreeNode* root) {
        return !root->left and !root->right;
    }

    int getMx(TreeNode* root, int& mx) {
        if (!root) {
            return 0;
        }
        if (isLeaf(root)) {
            mx = max(mx, root->val);
            return root->val;
        }

        int lsum = getMx(root->left, mx);
        int rsum = getMx(root->right, mx);

        int nodeMx = max({ root->val, lsum + root->val, rsum + root->val, lsum + rsum + root->val });
        mx = max(mx, nodeMx);

        return max(root->val, max(lsum, rsum) + root->val);
    }

    int maxPathSum(TreeNode* root) {
        if (isLeaf(root)) {
            return root->val;
        }

        int mx = INT_MIN;
        getMx(root, mx);

        return mx;
    }
};

int main() {
    return 0;
}