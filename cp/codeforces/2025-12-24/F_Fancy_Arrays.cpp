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

int power(int a, int x, int mod) {
    int res = 1;
    while (x) {
        if (x & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        x >>= 1;
    }
    return res;
}

template <typename T> class Matrix {
  public:
    vector<vector<T>> mat;
    int rows, cols;

    // Constructor: rows x cols, optionally identity (only for square matrices)
    Matrix(int r, int c, bool identity = false) : rows(r), cols(c) {
        mat.assign(r, vector<T>(c, 0));
        if (identity) {
            assert(r == c); // identity only for square
            for (int i = 0; i < r; i++) mat[i][i] = 1;
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
    Matrix<T> power(int exp) const {
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
    int n, x, k;
    cin >> n >> x >> k;

    // possible cnt of starting values: (x + k)
    // for each n - 1 transitions
    // there are +k, -k, 0 => (2k + 1) possible next values

    int nxt = power(2 * k + 1, n - 1, mod);
    int total = (((x + k) % mod) * nxt) % mod;

    // for the walks in [0, x - 1]
    int low = 0;
    if (x > 0) {
        // transition
        // i -> j : |i - j| <= k
        Matrix<int> trans(x, x);
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                if (abs(i - j) <= k) trans.mat[i][j] = 1;
            }
        }
        trans = trans.power(n - 1);

        int sm = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                sm = (sm + trans.mat[i][j]) % mod;
            }
        }

        low = sm;
    }

    int res = (total - low + mod) % mod;
    cout << res << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}