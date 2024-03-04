#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        // using adjacency list:

        vector<vector<int>> adj(n);
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                int sum = adj[i].size() + adj[j].size();

                for (auto it : adj[i])
                {
                    if (it == j)
                    {
                        sum--;
                        break;
                    }
                }

                ans = max(sum, ans);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};
    int n = 4;

    cout << sol.maximalNetworkRank(n, roads) << endl;
    return 0;
}