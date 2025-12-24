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
const int inf = 1e18;
const int ninf = -1 * inf;
int mod = 1e9 + 7;

void solve( ) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<int, int> rsum, csum;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Calculate initial row sums
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += grid[i][j];
        }
        rsum[i] = sum;
    }

    // Calculate initial column sums
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += grid[i][j];
        }
        csum[j] = sum;
    }

    pii st = {0, 0};
    vector<pii> path;
    path.push_back(st);

    for (char c : s) {
        if (c == 'R') {
            st.second++;
        } else if (c == 'D') {
            st.first++;
        } else if (c == 'L') {
            st.second--;
        } else {
            st.first--;
        }
        path.push_back(st);
    }

    map<int, int> rc, cc;
    for (auto [r, c] : path) {
        rc[r]++;
        cc[c]++;
    }

    for (auto [r, c] : path) {
        if (grid[r][c] == 0) {
            if (rc[r] == 1) {
                grid[r][c] = -1 * rsum[r];
                rsum[r] = 0;
                csum[c] += grid[r][c];
                rc[r]--;
                cc[c]--;
            } else if (cc[c] == 1) {
                grid[r][c] = -1 * csum[c];
                csum[c] = 0;
                rsum[r] += grid[r][c];
                rc[r]--;
                cc[c]--;
            }
        }
    }

    for (auto [r, c] : path) {
        if (grid[r][c] == 0 && (rc[r] > 0 || cc[c] > 0)) {
            if (rc[r] == 1) {
                grid[r][c] = -1 * rsum[r];
                rsum[r] = 0;
                csum[c] += grid[r][c];
                rc[r]--;
                cc[c]--;
            } else if (cc[c] == 1) {
                grid[r][c] = -1 * csum[c];
                csum[c] = 0;
                rsum[r] += grid[r][c];
                rc[r]--;
                cc[c]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve( );
    }
    return 0;
}