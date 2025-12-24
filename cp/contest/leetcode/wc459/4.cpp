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
    using pii = pair<int, int>;

    int countTrapezoids(vector<vector<int>> &points) {
        int n = points.size( );
        map<pii, vector<pair<pii, pii>>> cnt;

        auto get_slope = [&](pii &a, pii &b) -> pii {
            int dx = b.first - a.first;
            int dy = b.second - a.second;
            if (dx == 0) return {1, 0};
            if (dy == 0) return {0, 1};
            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0) dx *= -1, dy *= -1;
            return {dy, dx};
        };

        for (int i = 0; i < n; i++) {
            pii a = {points[i][0], points[i][1]};
            for (int j = i + 1; j < n; j++) {
                pii b = {points[j][0], points[j][1]};
                pii slope = get_slope(a, b);
                cnt[slope].push_back({a, b});
            }
        }

        auto collin = [&](pii &a, pii &b, pii &c) -> bool {
            return (b.first - a.first) * (c.second - a.second) == (b.second - a.second) * (c.first - a.first);
        };

        auto all_collin = [&](pii &a, pii &b, pii &c, pii &d) -> bool {
            return collin(a, b, c) && collin(a, b, d) && collin(c, d, a) && collin(c, d, b);
        };

        ll res = 0;
        // for (auto &[slope, k] : cnt) res += 1LL * k * (k - 1) / 2;
        for (auto &[slope, vec] : cnt) {
            int m = vec.size( );
            for (int i = 0; i < m; i++) {
                auto &[a1, b1] = vec[i];
                for (int j = i + 1; j < m; j++) {
                    auto &[a2, b2] = vec[j];
                    set<pii> pts = {a1, b1, a2, b2};
                    if (pts.size( ) < 4) continue;
                    if (all_collin(a1, b1, a2, b2)) continue;
                    res++;
                }
            }
        }

        return res;
    }
};

int main( ) {
    vector<vector<vector<int>>> points = {
        {{-3, 2}, {3, 0}, {2, 3}, {3, 2}, {2, -3}},
        {{0, 0}, {1, 0}, {0, 1}, {2, 1}},
        {{-32, 12}, {-32, -94}, {-32, -15}, {-30, 88}},
        {{82, 7}, {82, -9}, {82, -52}, {82, 78}},
        {{71, -89}, {-75, -89}, {-9, 11}, {-24, -89}, {-51, -89}, {-77, -89}, {42, 11}},
    };
    Solution sol;
    for (auto &point : points) cout << sol.countTrapezoids(point) << endl;

    return 0;
}
