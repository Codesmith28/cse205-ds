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

    bool check(TreeNode* root, long long mn, long long mx) {
        if (!root) return true;
        if ((root->val <= mn) or (root->val >= mx)) return false;

        // for left subBST and right subBST
        bool c1 = check(root->left, mn, root->val);
        bool c2 = check(root->right, root->val, mx);

        return c1 and c2;
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};

int main() {

    return 0;
}