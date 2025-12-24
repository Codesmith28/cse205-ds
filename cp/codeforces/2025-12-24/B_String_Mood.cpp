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
    int n; // number of states
    cin >> n;

    // transition:
    /*
            h    s
        h [1-p  p]
        s [p  1-p]
    */

    // vowel -> 5 => flip
    // consonants -> 21 - 3 = 18 -> no change
    // s,d -> 2 -> sad
    // h -> 1 -> happy

    Matrix<int> trans(2, 2); // number of ways
    trans.mat[0][0] = 19;    // h -> h {18 + 1}
    trans.mat[0][1] = 7;     // h -> s {6 + 1}
    trans.mat[1][0] = 6;     // s -> h {5 + 1}
    trans.mat[1][1] = 20;    // s -> s {18 + 2}

    Matrix<int> start(2, 1);
    start.mat[0][0] = 1;
    start.mat[1][0] = 0;

    trans = trans.power(n);
    start = trans.mult(start);
    cout << start.mat[0][0] << endl;
    // dbg(start.mat);
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