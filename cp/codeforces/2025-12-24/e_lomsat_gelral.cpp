#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
        int n;
        cin >> n;
        vector<int> col(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> col[i];
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        int root = 1;
        vector<int> res(n + 1, 0);

        struct Data {
                map<int, int> *freq;
                int mxFq;
                long long sum;
                Data( ) : freq(nullptr), mxFq(0), sum(0) {
                }
                Data(map<int, int> *f, int m, long long s) : freq(f), mxFq(m), sum(s) {
                }
        };

        auto dfs = [&](auto &&go, int node, int par) -> Data {
                auto *freq = new map<int, int>( );
                (*freq)[col[node]] = 1;
                int mxFq = 1;
                long long sum = col[node];

                Data curr(freq, mxFq, sum);

                for (auto it : adj[node]) {
                        if (it == par) continue;
                        Data child = go(go, it, node);

                        // swaps freq, mxFq and sum together
                        if (child.freq->size( ) > curr.freq->size( )) swap(child, curr);

                        // merge child (smaller) into curr (larger)
                        for (auto &[c, f] : *child.freq) {
                                int now = 0;

                                auto itf = curr.freq->find(c);
                                if (itf != curr.freq->end( )) now = itf->second;
                                now += f;
                                (*curr.freq)[c] = now;

                                if (now > curr.mxFq) {
                                        curr.mxFq = now;
                                        curr.sum = c;
                                } else if (now == curr.mxFq) {
                                        curr.sum += c;
                                }
                        }
                }

                res[node] = (int)curr.sum;
                return curr;
        };

        dfs(dfs, root, -1);
        for (int i = 1; i <= n; i++) cout << res[i] << " ";
        cout << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        // cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
