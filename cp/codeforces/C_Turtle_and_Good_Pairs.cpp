#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define pci pair<char, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> fq;
    for (auto it : s) fq[it]++;

    vector<pci> fqv;
    for (auto it : fq) fqv.push_back({it.first, it.second});
    sort(begin(fqv), end(fqv), [](pci a, pci b) { return a.second > b.second; });

    queue<pci> q;
    for (auto it : fqv) q.push(it);

    string ans = "";
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        if (it.second > 0) {
            ans += it.first;
            it.second--;
            if (it.second > 0) q.push(it);
        } else {
            continue;
        }
    }

    cout << ans << endl;
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