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

    void maker(vector<vector<int>>& lvl, vector<int>& temp, TreeNode* root) {
        if (!root) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int lvlSize = q.size();

            for (int i = 0; i < lvlSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            lvl.push_back(temp);
            temp.clear();
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        // return the set of right most nodes at every level
        vector<vector<int>> lvl;
        vector<int> temp;
        maker(lvl, temp, root);

        vector<int> ans;
        for (auto it : lvl) {
            ans.push_back(it[it.size() - 1]);
        }

        return ans;
    }
};

int main() {
    return 0;
}