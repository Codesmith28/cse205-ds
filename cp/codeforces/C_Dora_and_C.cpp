#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int GCD = __gcd(a, b);

    vector<int> c(n);
    for (int &i : c) cin >> i;

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    vector<bool> pts(GCD, false);
    for (int i = 0; i < c.size(); i++) {
        int x = c[i] % GCD;
        pts[x] = true;
    }

    // largest gap in pts between 2 true values
    int ans = 0;
    for (int i = 0; i < GCD; i++) {
        if (pts[i]) {
            int j = i;
            while (j < GCD && pts[j]) j++;
            ans = max(ans, j - i);
            i = j;
        }
    }

    // move the first half at the end and find the largest gap
    int ans2 = 0;
    for (int i = 0; i < GCD; i++) {
        if (pts[i]) {
            int j = i;
            while (j < GCD && pts[j]) j++;
            ans2 = max(ans2, j - i);
            i = j;
        }
    }

    cout << min(ans, ans2) << endl;
}

// void solve() {
//     int n, a, b;
//     cin >> n >> a >> b;

//     vector<int> c(n);
//     for (int &i : c) cin >> i;
//     sort(begin(c), end(c));
//     c.erase(unique(begin(c), end(c)), end(c));

//     if (abs(a - b) == 1) {
//         cout << 0 << endl;
//         return;
//     }

//     int sz = c.size();
//     int mx = c[sz - 1], mn = c[0];

//     int prev = INT_MAX;
//     priority_queue<int, vector<int>, greater<int>> pq(begin(c), end(c));

//     if (a != b) a = __gcd(a, b);

//     vector<int> final;

//     while (pq.top() != mx) {
//         int curr = pq.top();
//         pq.pop();
//         int cd = mx - curr;
//         curr += (cd / a) * a;
//         final.push_back(curr);
//     }

//     final.push_back(mx);
//     mx = *max_element(begin(final), end(final));
//     mn = *min_element(begin(final), end(final));

//     prev = mx - mn;

//     // int diff = mx - mn;
//     // while (diff < prev) {
//     //     int x = pq.top();
//     //     pq.pop();
//     //     x += a;
//     //     if (x > mx) mx = x;
//     //     pq.push(x);
//     //     int mn = pq.top();
//     //     diff = mx - mn;
//     //     if (diff >= prev) break;
//     //     prev = diff;
//     // }

//     cout << prev << endl;
// }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}