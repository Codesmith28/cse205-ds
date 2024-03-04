#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:

    bool isValid(vector<vector<char>>& board, int i, int j, int n, int m) {
        if (i >= 0 and i < n and j >= 0 and j < m and board[i][j] == 'O') {
            return true;
        }
        return false;
    }

    // marks only those which are connected at the boundaries:
    void marker(vector<vector<char>>& board, int i, int j, int n, int m) {
        board[i][j] = 'B';

        if (isValid(board, i + 1, j, n, m)) {
            marker(board, i + 1, j, n, m);
        }
        if (isValid(board, i, j + 1, n, m)) {
            marker(board, i, j + 1, n, m);
        }
        if (isValid(board, i - 1, j, n, m)) {
            marker(board, i - 1, j, n, m);
        }
        if (isValid(board, i, j - 1, n, m)) {
            marker(board, i, j - 1, n, m);
        }
    }

    void convert(vector<vector<char>>& board, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        /* marking the boundaries: */
        // left -> right on top and bottom side:
        for (int i = 0; i < n; i++) {
            int j = 0;
            if (board[i][j] == 'O') {
                marker(board, i, j, n, m);
            }

            j = m - 1;
            if (board[i][j] == 'O') {
                marker(board, i, j, n, m);
            }
        }

        // top -> bottom on left and right side:
        for (int j = 0; j < m; j++) {
            int i = 0;
            if (board[i][j] == 'O') {
                marker(board, i, j, n, m);
            }

            i = n - 1;
            if (board[i][j] == 'O') {
                marker(board, i, j, n, m);
            }
        }

        convert(board, n, m);
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = { {'X', 'X', 'X', 'X'},
                                   {'X', 'O', 'O', 'X'},
                                   {'X', 'X', 'O', 'X'},
                                   {'X', 'O', 'X', 'X'} };
    sol.solve(board);

    for (auto it : board) {
        for (auto x : it) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}