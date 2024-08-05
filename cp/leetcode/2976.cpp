#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define ll long long
#define vc vector<char>
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define vvii vector<vector<pii>>

class Solution {
  public:
    ll minimumCost(string src, string tar, vc &og, vc &changed, vi &cost) {
        vvii adj(26);
        int n = og.size();
        for (int i = 0; i < n; i++) {
            adj[og[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        vvi minConvCosts(26, vi(26));
        for (int i = 0; i < 26; i++) {
            minConvCosts[i] = dj(i, adj);
        }

        ll totalCost = 0;
        int m = src.length();
        for (int i = 0; i < m; i++) {
            if (src[i] != tar[i]) {
                ll charConvCost = minConvCosts[src[i] - 'a'][tar[i] - 'a'];
                // if (charConvCost == -1) return -1;
                totalCost += charConvCost;
            }
        }
        return totalCost;
    }

  private:
    vi dj(int st, const vvii &adj) {
        priority_queue<pii, vii, greater<pii>> pq;
        pq.push({0, st});
        vi minCost(26, -1);

        while (!pq.empty()) {
            auto [curCost, curChar] = pq.top();
            pq.pop();

            if (minCost[curChar] != -1 && minCost[curChar] < curCost) continue;

            for (auto &[targChar, convCost] : adj[curChar]) {
                ll newTotalCost = curCost + convCost;
                if (minCost[targChar] == -1 || newTotalCost < minCost[targChar]) {
                    minCost[targChar] = newTotalCost;
                    pq.push({newTotalCost, targChar});
                }
            }
        }
        return minCost;
    }
};

int main() {
    vector<string> src = {"abcd", "aaaa"};
    vector<string> tar = {"dcba", "bbbb"};
    vector<vc> og = {
        {'a', 'b', 'c', 'c', 'e', 'd'},
        {'a', 'c'}
    };
    vector<vc> change = {
        {'b', 'c', 'b', 'e', 'b', 'e'},
        {'c', 'b'}
    };
    vector<vi> cost = {
        {2, 5, 5, 1, 2, 20},
        {1, 2}
    };

    Solution s;
    for (int i = 0; i < src.size(); i++) {
        cout << s.minimumCost(src[i], tar[i], og[i], change[i], cost[i]) << endl;
    }
    return 0;
}