#include <bits/stdc++.h>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    unordered_map<int, int, custom_hash> freq;
    for (int i : a) freq[i]++;

    vector<pii> fq(freq.begin(), freq.end());
    sort(fq.begin(), fq.end());

    int m = fq.size();
    int l = 0, mx = 0, dis = 0, cnt = 0;

    for (int r = 0; r < m; r++) {
        if (r > 0 && fq[r].first - fq[r - 1].first == 1) {
            dis++;
            cnt += fq[r].second;
        } else {
            dis = 1;
            cnt = fq[r].second;
            l = r;
        }
        while (dis > k) {
            cnt -= fq[l].second;
            dis--;
            l++;
        }
        mx = max(mx, cnt);
    }

    cout << mx << endl;
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