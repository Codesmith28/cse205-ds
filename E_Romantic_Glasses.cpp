#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

int find(vector<int>& arr, int n, int sum) {
    unordered_map<int, int> prevSum;
    int res = 0;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        curr += arr[i];

        if (curr == sum) {
            res++;
        }

        if (prevSum.find(curr - sum) != prevSum.end()) {
            res += (prevSum[curr - sum]);
        }

        prevSum[curr]++;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2) a[i] = -a[i];
    }

    int count = find(a, n, 0);
    cout << (count ? "YES" : "NO") << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}