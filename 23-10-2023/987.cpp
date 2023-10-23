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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({ root, {0,0} });

        // 2 keys: x and y coord
        // 1 value: list of all nodes
        map<int, map<int, vector<int>>> mp;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            TreeNode* node = top.first;
            int x = top.second.first;
            int y = top.second.second;

            mp[x][y].push_back(node->val);

            if (node->left) {
                q.push({ node->left, {x - 1, y + 1} });
            }
            if (node->right) {
                q.push({ node->right, {x + 1, y + 1} });
            }
        }

        vector<vector<int>> ans;

        for (auto it : mp) {
            vector<int> temp;
            for (auto i : it.second) {
                sort(i.second.begin(), i.second.end());
                for (auto j : i.second) {
                    temp.push_back(j);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    return 0;
}