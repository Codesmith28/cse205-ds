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

const int mod = 4294967296; // 2^32

template <typename T> class Matrix {
  public:
    vector<vector<T>> mat;
    int rows, cols;

    Matrix(int r, int c, bool identity = false) : rows(r), cols(c) {
        mat.assign(r, vector<T>(c, 0));
        if (identity) {
            assert(r == c);
            for (int i = 0; i < r; i++) mat[i][i] = 1;
        }
    }

    Matrix<T> mult(const Matrix<T> &postMult) const {
        assert(cols == postMult.rows);
        Matrix<T> res(rows, postMult.cols);
        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                if (!mat[i][k]) continue;
                for (int j = 0; j < postMult.cols; j++) {
                    unsigned __int128 val = (unsigned __int128)mat[i][k] * postMult.mat[k][j] + res.mat[i][j];
                    res.mat[i][j] = (T)(val % mod);
                }
            }
        }
        return res;
    }

    Matrix<T> add(const Matrix<T> &other) const {
        Matrix<T> res(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) res.mat[i][j] = (mat[i][j] + other.mat[i][j]) % mod;
        return res;
    }
};

// Returns pair {A^n, I + A + ... + A^(n-1)}
template <typename T> pair<Matrix<T>, Matrix<T>> powerWithSeries(const Matrix<T> &A, long long n) {
    if (n == 1) return {A, Matrix<T>(A.rows, A.cols, true)};
    if (n % 2 == 0) {
        auto half = powerWithSeries(A, n / 2);
        Matrix<T> Pm = half.first;
        Matrix<T> Sm = half.second;
        Matrix<T> P2m = Pm.mult(Pm);
        Matrix<T> S2m = Sm.add(Pm.mult(Sm));
        return {P2m, S2m};
    } else {
        auto prev = powerWithSeries(A, n - 1);
        Matrix<T> Pn_1 = prev.first;
        Matrix<T> Sn_1 = prev.second;
        Matrix<T> Sn = Sn_1.add(Pn_1);
        Matrix<T> Pn = Pn_1.mult(A);
        return {Pn, Sn};
    }
}

void solve( ) {
    int n;
    cin >> n; // maximum moves allowed

    const int N = 8;
    const int SZ = N * N;

    vector<int> dx = {+2, +2, -2, -2, +1, +1, -1, -1};
    vector<int> dy = {+1, -1, +1, -1, +2, -2, +2, -2};

    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    auto to1d = [&](int x, int y) -> int {
        return x * N + y;
    };

    vector<vector<int>> adj(SZ, vector<int>(SZ, 0));
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            int u = to1d(x, y);
            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (valid(nx, ny)) {
                    int v = to1d(nx, ny);
                    adj[u][v] = 1;
                }
            }
        }
    }

    Matrix<int> trans(SZ, SZ);
    trans.mat = adj;

    // Compute S = I + A + ... + A^n
    auto [An, S] = powerWithSeries(trans, n + 1);

    int total = 0;
    for (int j = 0; j < SZ; j++) total = (total + S.mat[0][j]) % mod;
    cout << total << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    while (testCases--) solve( );
}
