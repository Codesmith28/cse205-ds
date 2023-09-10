#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto it : accounts) {
            int temp = 0;
            for (auto x : it) {
                temp += x;
            }
            ans = max(ans, temp);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> accounts = { {1,2,3},{3,2,1} };
    cout << sol.maximumWealth(accounts) << endl;
    
    return 0;
}