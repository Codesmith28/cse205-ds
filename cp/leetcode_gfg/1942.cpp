#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define pii pair<int, int>

struct frn {
    int arr, dep, idx;
    bool operator<(const frn &r) const {
        return arr < r.arr;
    }
};

class Solution {
  public:
    int smallestChair(vector<vector<int>> &t, int targetFriend) {
        int n = t.size();

        vector<frn> time;
        for (int i = 0; i < n; i++) {
            time.push_back({t[i][0], t[i][1], i});
        }

        sort(time.begin(), time.end(), [](struct frn a, struct frn b) {
            return a.arr < b.arr;
        });

        vector<int> res(n, -1);
        int chair = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        set<int> avail;

        for (int i = 0; i < n; i++) {
            dbg(pq);

            while (!pq.empty() and pq.top().first <= time[i].arr) {
                avail.insert(pq.top().second);
                pq.pop();
            }

            int curr;
            if (!avail.empty()) {
                curr = *avail.begin();
                avail.erase(avail.begin());
            } else {
                curr = chair++;
            }

            res[time[i].idx] = curr;
            pq.push({time[i].dep, curr});
        }

        return res[targetFriend];
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> t(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> t[i][0] >> t[i][1];
    }
    int targetFriend;
    cin >> targetFriend;
    Solution s;
    cout << s.smallestChair(t, targetFriend) << endl;
    return 0;
}
