#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

int minimumOperations(string str1, string str2) {
    // Write your code here
    int cost = 5;
    int n = str1.size( );
    int m = str2.size( );
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i * cost;
    for (int j = 0; j <= m; j++) dp[0][j] = j * cost;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int a = dp[i - 1][j] + cost;
                int b = dp[i][j - 1] + cost;
                int c = dp[i - 1][j - 1] + cost;
                dp[i][j] = min({a, b, c});
            }
        }
    }
    return 5000 - dp[n][m];
}

int main( ) {
    string s1 = "doselect";
    string s2 = "selecd";
    cout << minimumOperations(s1, s2) << endl;
    return 0;
}
