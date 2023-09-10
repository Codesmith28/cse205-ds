#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }

        int n = matrix[0].size();
        int m = matrix.size();

        int t = 0;
        int b = m - 1;
        int l = 0;
        int r = n - 1;

        // 4 pointer approach
        while (t <= b and l <= r) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            t++;

            for (int i = t; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            r--;

            if (t <= b) {
                for (int i = r; i >= l; i--) {
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }

            if (l <= r) {
                for (int i = b; i >= t; i--) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<int> ans = sol.spiralOrder(matrix);

    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}