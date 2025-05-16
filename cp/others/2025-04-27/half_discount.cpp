/* Description

Problem Statement

You are given a graph of Cities. The cities are numbered from 1 to N. You are in the City 1. You have M routes, which come along with a cost. You have a special talent where you get the cost of the routes you move in. Find the maximum cost you can acquire by moving from City 1 to City N.

Note: You can assume that it's always possible to reach from City 1 to City N. However, if you can get an arbitrarily large score, return −1.

Input Format

    The first line contains an integer N, the total number of Cities.
    The second line contains an integer M, the total number of routes.
    The third line contains an integer 3, representing that there will be 3 integers in the next M lines.
    The next M lines contains 3 integers A B C - representing a route from A to B with a cost of C.

Output Format

    The maximum cost you can acquire by moving from City 1 to City N.

Constraints

    1 ≤ N ≤ 2500
    1 ≤ M ≤ 5000
    1 ≤ A , B ≤ N
    -1000000000 ≤ C ≤ 1000000000


input:
4
5
3
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

output:
5 */

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

const long long INF = 1e18;
const long long NINF = -1e18;

int main( ) {
    int n, m, dummy;
    cin >> n >> m >> dummy;

    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // convert to 0-based indexing and negate cost
        edges[i] = {a - 1, b - 1, -c};
    }

    // Bellman-Ford
    auto bellman_ford = [&](int start) -> vector<long long> {
        vector<long long> dist(n, INF);
        dist[start] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (auto &e : edges) {
                int a = e[0], b = e[1];
                long long x = e[2];
                if (dist[a] != INF && dist[a] + x < dist[b]) {
                    dist[b] = max(dist[a] + x, NINF);
                }
            }
        }

        // Detect negative cycle (positive cycle in original graph)
        vector<bool> in_negative_cycle(n, false);
        for (int i = 0; i < n; i++) {
            for (auto &e : edges) {
                int a = e[0], b = e[1];
                long long x = e[2];
                if (dist[a] != INF && dist[a] + x < dist[b]) {
                    dist[b] = NINF;
                    in_negative_cycle[b] = true;
                }
            }
        }

        return dist;
    };

    vector<long long> dist = bellman_ford(0);

    if (dist[n - 1] == NINF) {
        cout << -1 << endl;
    } else {
        cout << -dist[n - 2] << endl; // negate to get max cost
    }

    return 0;
}
