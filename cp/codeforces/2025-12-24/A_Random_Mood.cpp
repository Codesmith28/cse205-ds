#include <bits/stdc++.h>
#include <iomanip>
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
                for (int j = 0; j < postMult.cols; j++) res.mat[i][j] += mat[i][k] * postMult.mat[k][j];
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
    double p;
    cin >> n >> p;

    // p -> for mood change
    // 1 - p -> for mood not changed

    // transition:
    /*
            h    s
        h [1-p  p]
        s [p  1-p]
    */

    // nextState = transition * currState
    // state = {1, 0} [happy, sad]

    Matrix<double> state(2, 1);
    Matrix<double> trans(2, 2);

    state.mat[0][0] = 1; // happy
    state.mat[1][0] = 0; // sad

    trans.mat[0][0] = 1 - p; // happy -> happy
    trans.mat[0][1] = p;     // happy -> sad
    trans.mat[1][0] = p;     // sad -> happy
    trans.mat[1][1] = 1 - p; // sad -> sad

    trans = trans.power(n);
    Matrix<double> res = trans.mult(state);
    cout << fixed << setprecision(10) << res.mat[0][0] << endl;
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