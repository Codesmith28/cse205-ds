#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2));

        // profit in the first day is not considered 

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; i++) {

            // buy the current stock:
            // negative means buying the stock hence amount reduces
            dp[i][0] = max(dp[i - 1][0], -prices[i]);

            // sell the current stock:
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return max(dp.back()[0], dp.back()[1]);
    }
};

int main()
{
    Solution s;
    vector<int> prices = { 7,1,5,3,6,4 };

    cout << s.maxProfit(prices) << endl;
    return 0;
}