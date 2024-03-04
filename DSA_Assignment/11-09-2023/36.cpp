#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // map the presence
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> grid(9, vector<bool>(9, false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {

                if (board[i][j] != '.') {

                    int num = board[i][j] - '1';

                    // spliting into grids of 3 so i->i/3 and j->j/3
                    int gridNum = (i / 3) * 3 + (j / 3);

                    // if present then return false, else set it to true
                    if (row[i][num] or col[j][num] or grid[gridNum][num]) {
                        return false;
                    }

                    row[i][num] = true;
                    col[j][num] = true;
                    grid[gridNum][num] = true;
                }
            }
        }

        return true;
    }
};


int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << sol.isValidSudoku(board) << endl;
    return 0;
}