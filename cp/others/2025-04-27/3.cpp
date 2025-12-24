#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

const int N = 1e6 + 6;
const __int128 B = 33;                  // base
const __int128 M = 1000000000000000003; // mod

__int128 add(__int128 a, __int128 b, __int128 m) {
    __int128 res = (a + b) % m;
    if (res < 0) res += m;
    return res;
}

__int128 mul(__int128 a, __int128 b, __int128 m) {
    __int128 res = (a * b) % m;
    if (res < 0) res += m;
    return res;
}

__int128 pow(__int128 a, __int128 b, __int128 m) {
    __int128 res = 1;
    while (b) {
        if (b & 1) res = mul(res, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return res;
}

__int128 P[N], I[N], H[N];

void pre( ) {
    P[0] = 1;
    for (int i = 1; i < N; i++) P[i] = mul(P[i - 1], B, M);
    __int128 invB = pow(B, M - 2, M);
    I[0] = 1;
    for (int i = 1; i < N; i++) I[i] = mul(I[i - 1], invB, M);
}

void build(const vector<char> &s, int n) {
    H[0] = mul(P[0], s[0] - 'a' + 1, M);
    for (int i = 1; i < n; i++) {
        H[i] = add(H[i - 1], mul(P[i], s[i] - 'a' + 1, M), M);
    }
}

__int128 getH(int x, int y) {
    if (x == 0) return H[y];
    __int128 res = add(H[y], -H[x - 1], M);
    return mul(res, I[x], M);
}

class Solution {
  public:
    int countCells(vector<vector<char>> &g, string p) {
        using pii = pair<int, int>;
        int r = g.size( ), c = g[0].size( ), l = p.length( ), t = r * c;
        if (l > t) return 0;

        pre( );

        vector<char> pv(p.begin( ), p.end( ));
        build(pv, l);
        __int128 ph = getH(0, l - 1);

        vector<char> h(t);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) h[i * c + j] = g[i][j];
        build(h, t);

        vector<vector<bool>> m(r, vector<bool>(c, false));
        for (int s = 0; s <= t - l; s++) {
            if (getH(s, s + l - 1) == ph) {
                for (int k = s; k < s + l; k++) {
                    int i = k / c, j = k % c;
                    m[i][j] = true;
                }
            }
        }

        vector<char> v(t);
        for (int j = 0; j < c; j++)
            for (int i = 0; i < r; i++) v[j * r + i] = g[i][j];
        build(v, t);

        set<pii> res;
        for (int s = 0; s <= t - l; s++) {
            if (getH(s, s + l - 1) == ph) {
                for (int k = s; k < s + l; k++) {
                    int i = k % r, j = k / r;
                    if (m[i][j]) res.insert({i, j});
                }
            }
        }

        return res.size( );
    }
};

int main( ) {
    vector<vector<vector<char>>> g = {
        {{'a', 'a', 'c', 'c'}, {'b', 'b', 'b', 'c'}, {'a', 'a', 'b', 'a'}, {'c', 'a', 'a', 'c'}, {'a', 'a', 'c', 'c'}},
        {{'c', 'a', 'a', 'a'}, {'a', 'a', 'b', 'a'}, {'b', 'b', 'a', 'a'}, {'a', 'a', 'b', 'a'}},
        {{'a'}}
    };
    vector<string> p = {"abaca", "aba", "a"};

    Solution sol;
    for (int i = 0; i < g.size( ); i++) {
        cout << sol.countCells(g[i], p[i]) << endl;
    }
    return 0;
}