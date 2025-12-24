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
const int mod = 1e9 + 7;

template <typename T> class Matrix {
  public:
    vector<vector<T>> mat;
    int rows, cols;

    // Constructor: rows x cols, optionally identity (only for square matrices)
    Matrix(int r, int c, bool identity = false) : rows(r), cols(c) {
        mat.assign(r, vector<T>(c, 0));
        if (identity) {
            assert(r == c); // identity only for square
            for (int i = 0; i < r; ++i) mat[i][i] = 1;
        }
    }

    // Multiply this matrix with another
    Matrix<T> mult(const Matrix<T> &postMult) const {
        assert(cols == postMult.rows);
        Matrix<T> res(rows, postMult.cols);
        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                if (!mat[i][k]) continue;
                for (int j = 0; j < postMult.cols; j++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * postMult.mat[k][j]) % mod;
                }
            }
        }
        return res;
    }

    // Raise square matrix to power
    Matrix<T> power(long long exp) const {
        assert(rows == cols);
        Matrix<T> res(rows, cols, true); // identity
        Matrix<T> base = *this;
        while (exp > 0) {
            if (exp & 1) res = res.mult(base);
            base = base.mult(base);
            exp >>= 1;
        }
        return res;
    }
};

void solve( ) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }

    Matrix<int> trans(n + 1, n + 1);
    trans.mat = adj;
    trans = trans.power(k);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum = (sum + trans.mat[i][j]) % mod;
        }
    }

    cout << sum << endl;
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