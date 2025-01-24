#include <bits/stdc++.h>
/*#ifndef ONLINE_JUDGE*/
/*#include "debug.h"*/
/*#else*/
/*#define dbg(x...)*/
/*#endif*/

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;
int mod = 1e9 + 7;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {
    }
    bool operator<(const Edge &other) const {
        return w > other.w;
    }
};

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin( ), parent.end( ), 0);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};

void solve( ) {
    int n;
    cin >> n;
    vector<int> x(n), a(n);
    for (int &i : x) cin >> i;
    for (int &i : a) cin >> i;

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = abs(x[i] - x[j]) * min(a[i], a[j]);
            edges.emplace_back(i, j, weight);
        }
    }

    priority_queue<Edge> pq;
    for (const Edge &e : edges) {
        pq.push(e);
    }

    UnionFind uf(n);
    int total_cost = 0;
    int edges_used = 0;

    while (!pq.empty( ) && edges_used < n - 1) {
        Edge edge = pq.top( );
        pq.pop( );
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unite(edge.u, edge.v);
            total_cost += edge.w;
            edges_used++;
        }
    }

    cout << total_cost << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) solve( );

    return 0;
}
