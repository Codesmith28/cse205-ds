#include <bits/stdc++.h>
#include <vector>
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

void andPref(const vector<int> &a) {
    vector<int> prefix(a.size());
    prefix[0] = a[0];
    for (int i = 1; i < a.size(); i++) {
        prefix[i] = prefix[i - 1] & a[i];
    }
    for (int it : prefix) {
        cout << it << " ";
    }
    cout << endl;
}

void xorPref(const vector<int> &a) {
    vector<int> prefix(a.size());
    prefix[0] = a[0];
    for (int i = 1; i < a.size(); i++) {
        prefix[i] = prefix[i - 1] ^ a[i];
    }
    for (int it : prefix) {
        cout << it << " ";
    }
    cout << endl;
}

void andSuf(const vector<int> &a) {
    vector<int> suffix(a.size());
    suffix[a.size() - 1] = a[a.size() - 1];
    for (int i = a.size() - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] & a[i];
    }
    for (int it : suffix) {
        cout << it << " ";
    }
    cout << endl;
}

void xorSuf(const vector<int> &a) {
    vector<int> suffix(a.size());
    suffix[a.size() - 1] = a[a.size() - 1];
    for (int i = a.size() - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] ^ a[i];
    }
    for (int it : suffix) {
        cout << it << " ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    // 3 : 3 3 1
    // 5: 5 5 5  5 1
    vector<int> ans(n - 1, n);
    ans.push_back(1);

    for (int it : ans) {
        cout << it << " ";
    }
    cout << endl;

    // andPref(ans);
    // xorPref(ans);
    // andSuf(ans);
    // xorSuf(ans);
    // cout << "-------------------" << endl;
}

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