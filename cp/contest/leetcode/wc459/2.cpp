#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    using ll = long long;

    const int mod = 1e9 + 7;
    ll power(int a, int x, int mod) {
        ll res = 1;
        while (x) {
            if (x & 1) res = 1LL * res * a % mod;
            a = 1LL * a * a % mod;
            x = x >> 1;
        }
        return res;
    }

    int countTrapezoids(vector<vector<int>> &points) {
        map<int, int> mp;
        for (auto &p : points) mp[p[1]]++; // same y-level

        auto nc2 = [](int n) -> ll {
            if (n < 2) return 0LL;
            return 1LL * n * (n - 1) / 2;
        };

        // choose any 2 per y
        vector<ll> combs;
        for (auto &[y, cnt] : mp) {
            if (cnt >= 2) combs.push_back(nc2(cnt));
        }

        ll sum = 0, sum_sq = 0;
        for (ll c : combs) {
            sum = (sum + c) % mod;
            sum_sq = (sum_sq + c * c % mod) % mod;
        }

        ll res = (sum * sum % mod - sum_sq + mod) % mod;
        res = (res * power(2, mod - 2, mod)) % mod;

        return res;
    }
};

int main( ) {
    vector<vector<vector<int>>> points = {
        {{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}},
        {{0, 0}, {1, 0}, {0, 1}, {2, 1}},
    };
    Solution sol;
    for (auto &point : points) cout << sol.countTrapezoids(point) << endl;

    return 0;
}