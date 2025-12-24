#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

template <typename T> class Matrix {
      public:
        vector<vector<T>> mat;
        int rows, cols;

        // constructor
        Matrix(int r, int c, bool identity = false) : rows(r), cols(c) {
                mat.assign(r, vector<T>(c, 0));
                if (identity) {
                        assert(r == c);
                        for (int i = 0; i < r; i++) mat[i][i] = 1;
                }
        }

        // matrix multiplication
        Matrix<T> mult(const Matrix<T> &postMult) const {
                assert(cols == postMult.rows);
                Matrix<T> res(rows, postMult.cols);
                for (int i = 0; i < rows; i++) {
                        for (int k = 0; k < cols; k++) {
                                if (mat[i][k] == 0) continue;
                                for (int j = 0; j < postMult.cols; j++) {
                                        res.mat[i][j] += mat[i][k] * postMult.mat[k][j];
                                }
                        }
                }
                return res;
        }

        // binary exponentiation of matrix for faster computation of large powers
        Matrix<T> power(long long exp) const {
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
};

int main( ) {
        // weather on the first day
        Matrix<double> current_weather(2, 1);
        current_weather.mat[0][0] = 0.5; // Sunny
        current_weather.mat[1][0] = 0.5; // Rainy

        // transition matrix
        Matrix<double> transition(2, 2);
        transition.mat[0][0] = 0.9; // sunny -> sunny
        transition.mat[0][1] = 0.3; // rainy -> sunny
        transition.mat[1][0] = 0.1; // sunny -> rainy
        transition.mat[1][1] = 0.7; // rainy -> rainy

        int days;
        cout << "Enter the number of days: " << endl;
        cin >> days;

        for (int i = 1; i <= days; i++) {
                Matrix<double> powered = transition.power(i);
                Matrix<double> future_weather = powered.mult(current_weather);
                cout << "After " << i << " day(s):\n";
                cout << "  Sunny | Rainy probability = " << fixed << setprecision(20) << future_weather.mat[0][0] << " | " << future_weather.mat[1][0] << "\n";
        }

        return 0;
}
