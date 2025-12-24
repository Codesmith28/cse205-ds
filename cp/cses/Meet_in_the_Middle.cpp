#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define int long long
#define pii pair<int, int>

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());

    int n1 = n / 2;
    vector<int> left(a.begin(), a.begin() + n1);
    vector<int> right(a.begin() + n1, a.end());

    // dbg(left); dbg(right);

    auto subsets = [&](vector<int> &arr, int offset) -> vector<int> {
        int n = arr.size();
        vector<int> sums;
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum += a[j + offset];
                }
            }
            sums.push_back(sum);
        }
        return sums;
    };

    vector<int> leftSums = subsets(left, 0);
    vector<int> rightSums = subsets(right, n / 2);

    sort(leftSums.begin(), leftSums.end());
    sort(rightSums.begin(), rightSums.end());

    // dbg(leftSums, rightSums);

    int cnt = 0;

    for (int &i : leftSums) {
        auto up = upper_bound(rightSums.begin(), rightSums.end(), m - i);
        auto low = lower_bound(rightSums.begin(), rightSums.end(), m - i);
        cnt += (up - low);
    }

    cout << cnt << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
