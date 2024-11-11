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

struct cust {
    int arr, dep, idx;
    bool operator<(const cust &r) const {
        return arr < r.arr;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<cust> cust(n);
    for (int i = 0; i < n; i++) {
        cin >> cust[i].arr >> cust[i].dep;
        cust[i].idx = i;
    }

    sort(cust.begin(), cust.end(), [](struct cust a, struct cust b) { return a.arr < b.arr; });

    vector<int> res(n, -1);
    int rooms = 1, mx = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) {
        if (pq.size() == 0) {
            res[cust[i].idx] = rooms;
            pq.push({cust[i].dep, rooms});
            rooms++;
        } else {
            if (pq.top().first < cust[i].arr) {
                res[cust[i].idx] = pq.top().second;
                auto [currDep, currRooms] = pq.top();
                pq.pop();
                pq.push({cust[i].dep, currRooms});
            } else {
                res[cust[i].idx] = rooms;
                pq.push({cust[i].dep, rooms});
                rooms++;
            }
        }
        mx = max(mx, (int)pq.size());
    }

    cout << mx << endl;
    for (int &i : res) cout << i << " ";
    cout << endl;
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
