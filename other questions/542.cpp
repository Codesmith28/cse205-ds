#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // dp approach:
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 1e9)); // Initialize to a large value

        // normal traversal:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // stores the occurence of all zeros:
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }

                // as we need to check the prior in dp
                // hence we can only check for top-left in this nested loop
                else
                {
                    if (i > 0)
                    { // top position
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    if (j > 0)
                    { // left position
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }
        }

        // reverse traversal:
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                // stores the occurence of all zeros:
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }

                // as we need to check the prior in dp
                // hence we can only check for bottom-right in this nested loop
                else
                {
                    if (i < n - 1)
                    { // bottom position
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }
                    if (j < m - 1)
                    { // right position
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                }
            }
        }

        return dp;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

    vector<vector<int>> ans = sol.updateMatrix(mat);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}