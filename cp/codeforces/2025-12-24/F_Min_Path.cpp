#include <bits/stdc++.h>
#include <cassert>
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

template <typename T> class Matrix {
  public:
    vector<vector<T>> mat;
    int rows, cols;

    // Constructor: r x c, optionally identity (only for square matrices)
    Matrix(int r, int c, bool identity = false) : rows(r), cols(c) {
        mat.assign(r, vector<T>(c, inf));
        if (identity) {
            assert(r == c);
            for (int i = 0; i < r; i++) mat[i][i] = 0;
        }
    }

    // Standard multiplication
    Matrix<T> mult(const Matrix<T> &postMult) const {
        assert(cols == postMult.rows);
        Matrix<T> res(rows, postMult.cols);
        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                if (!mat[i][k]) continue;
                for (int j = 0; j < postMult.cols; j++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * postMult.mat[k][j]);
                }
            }
        }
        return res;
    }

    // Binary exponentiation
    Matrix<T> power(int exp) const {
        assert(rows == cols);
        Matrix<T> res(rows, cols, true);
        Matrix<T> base = *this;
        while (exp > 0) {
            if (exp & 1) res = res.mult(base);
            base = base.mult(base);
            exp >>= 1;
        }
        return res;
    }

    // minPlus path
    Matrix<T> minPlus(const Matrix<T> &post) const {
        assert(cols == post.rows);
        Matrix<T> res(rows, post.cols);
        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                if (mat[i][k] == inf) continue;
                for (int j = 0; j < post.cols; j++) {
                    if (post.mat[k][j] == inf) continue;
                    res.mat[i][j] = min(res.mat[i][j], mat[i][k] + post.mat[k][j]);
                }
            }
        }
        return res;
    }

    // Binary exponentiation for minPlus path (min,+)
    Matrix<T> minPlusPower(int exp) const {
        assert(rows == cols);
        Matrix<T> res(rows, cols, true);
        Matrix<T> base = *this;
        while (exp > 0) {
            if (exp & 1) res = res.minPlus(base);
            base = base.minPlus(base);
            exp >>= 1;
        }
        return res;
    }
};

void solve( ) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u][v] = min(adj[u][v], w);
    }

    Matrix<int> trans(n, n);
    trans.mat = adj;
    trans = trans.minPlusPower(k);

    int res = inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) res = min(res, trans.mat[i][j]);

    if (res == inf)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << res << endl;
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
