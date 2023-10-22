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

    void maker(vector<vector<int>>& ans, vector<int>& temp, TreeNode* root) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level

            for (int i = 0; i < levelSize; i++) {
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

            ans.push_back(temp); // Add the nodes at the current level to ans
            temp.clear(); // Clear temp for the next level
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        maker(ans, temp, root);

        return ans;
    }
};

int main() {

    return 0;
}