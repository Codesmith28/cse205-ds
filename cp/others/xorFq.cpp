#include <bits/stdc++.h>
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

int getmx(vector<int> &arr, int v) {
    int n = arr.size();
    vector<int> idx;

    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            idx.push_back(i);
        }
    }

    unordered_map<int, int> freqMap;
    int maxFreq = 0;

    if (idx[0] > 0) {
        for (int i = 0; i < idx[0]; i++) {
            if (arr[i] != v) {
                freqMap[arr[i]]++;
                maxFreq = max(maxFreq, freqMap[arr[i]]);
            }
        }
    }

    for (int i = 0; i < idx.size() - 1; i++) {
        int l = idx[i] + 1;
        int r = idx[i + 1] - 1;
        if (l <= r) {
            freqMap.clear();
            for (int j = l; j <= r; j++) {
                if (arr[j] != v) {
                    freqMap[arr[j]]++;
                    maxFreq = max(maxFreq, freqMap[arr[j]]);
                }
            }
        }
    }

    if (idx[idx.size() - 1] < n - 1) {
        freqMap.clear();
        for (int i = idx[idx.size() - 1] + 1; i < n; i++) {
            if (arr[i] != v) {
                freqMap[arr[i]]++;
                maxFreq = max(maxFreq, freqMap[arr[i]]);
            }
        }
    }

    return maxFreq + idx.size();
}

void solve() {
    int n, val;
    cin >> n >> val;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    cout << getmx(a, val) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}