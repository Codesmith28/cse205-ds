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
    // inorder dfs (left -> curr -> right) === (min -> mid -> max) 
    vector<int> in;

    void dfs(TreeNode* root, vector<int>& in) {
        if (!root) return;
        dfs(root->left, in);
        in.push_back(root->val);
        dfs(root->right, in);
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root, in);

        int st = 0, en = in.size() - 1;
        int sum = 0;

        while (st < en) {
            sum = in[st] + in[en];
            if (sum == k) return true;
            else if (sum > k) en--;
            else st++;
        }

        return false;
    }
};

int main() {

    return 0;
}