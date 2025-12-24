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

class BSTIterator {
public:

    int st;
    vector<int> v;

    void dfs(TreeNode* root, vector<int>& v) {
        if (!root) return;

        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }

    BSTIterator(TreeNode* root) {
        dfs(root, v);
        st = 0;
    }

    int next() {
        if (st < v.size()) return v[st++];
        return -1;
    }

    bool hasNext() {
        if (st < v.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {

    return 0;
}