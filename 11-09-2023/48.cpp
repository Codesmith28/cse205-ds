#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix[0].size();

        // swap the first and last:
        for (int i = 0; i < n / 2; i++) {
            swap(matrix[i], matrix[n - 1 - i]);
        }

        // take the transpose of the given matrix:
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    sol.rotate(matrix);

    for (auto it : matrix) {
        for (auto x : it) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}