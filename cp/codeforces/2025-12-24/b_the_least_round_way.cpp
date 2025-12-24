#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e9;

void solve( ) {
        int n;
        cin >> n;

        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> c2(n, vector<int>(n, 0));
        vector<vector<int>> c5(n, vector<int>(n, 0));

        auto countf = [&](int x, int f) -> int {
                int cnt = 0;
                while (x && x % f == 0) {
                        x /= f;
                        cnt++;
                }
                return cnt;
        };

        bool zero = false;
        int zi = -1, zj = -1;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> a[i][j];
                        if (a[i][j] == 0) {
                                zero = true;
                                c2[i][j] = inf;
                                c5[i][j] = inf;
                                zi = i;
                                zj = j;
                        } else {
                                c2[i][j] = countf(a[i][j], 2);
                                c5[i][j] = countf(a[i][j], 5);
                        }
                }
        }

        auto recur = [&](vector<vector<int>> &cnt) -> vector<vector<int>> {
                vector<vector<int>> dp(n, vector<int>(n, inf));
                dp[0][0] = cnt[0][0];
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                if (i > 0) {
                                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + cnt[i][j]);
                                }
                                if (j > 0) {
                                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + cnt[i][j]);
                                }
                        }
                }
                return dp;
        };

        vector<vector<int>> dp2 = recur(c2);
        vector<vector<int>> dp5 = recur(c5);
        int ans = min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]);

        if (zero && ans > 1) {
                cout << 1 << endl;
                string path;
                path.append(zi, 'D');
                path.append(zj, 'R');
                path.append(n - 1 - zi, 'D');
                path.append(n - 1 - zj, 'R');
                cout << path << endl;
                return;
        }

        vector<vector<int>> *dp;
        if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1]) {
                dp = &dp2;
        } else {
                dp = &dp5;
        }

        string path;
        int i = n - 1, j = n - 1;
        while (i > 0 || j > 0) {
                if (i == 0) {
                        j--;
                        path.push_back('R');
                } else if (j == 0) {
                        i--;
                        path.push_back('D');
                } else if ((*dp)[i - 1][j] < (*dp)[i][j - 1]) {
                        i--;
                        path.push_back('D');
                } else {
                        j--;
                        path.push_back('R');
                }
        }
        reverse(path.begin( ), path.end( ));
        cout << ans << endl;
        cout << path << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        // cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
