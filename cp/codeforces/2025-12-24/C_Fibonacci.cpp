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
        for (int i = 0; i < rows; i++)
            for (int k = 0; k < cols; k++)
                for (int j = 0; j < postMult.cols; j++) res.mat[i][j] = (res.mat[i][j] + mat[i][k] * postMult.mat[k][j]) % mod;
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
    int n;
    cin >> n;

    // [an, an-1] = [[w, x], [y, z]] * [an-1, an-2]
    // w = x = y = 1, z = 0;

    Matrix<int> trans(2, 2);
    trans.mat[0][0] = 1;
    trans.mat[0][1] = 1;
    trans.mat[1][0] = 1;
    trans.mat[1][1] = 0;

    Matrix<int> start(2, 1);
    start.mat[0][0] = 1;
    start.mat[1][0] = 0;

    trans = trans.power(n);
    start = trans.mult(start);

    cout << start.mat[1][0] << endl;
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