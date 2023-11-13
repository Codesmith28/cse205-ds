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
    int idx = 0;
    TreeNode* maker(vector<int>& pre, int limit) {
        if (idx == pre.size() or pre[idx] > limit) return NULL;

        TreeNode* root = new TreeNode(pre[idx++]);
        root->left = maker(pre, root->val);
        root->right = maker(pre, limit);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        return maker(pre, INT_MAX);
    }
};

int main() {

    return 0;
}