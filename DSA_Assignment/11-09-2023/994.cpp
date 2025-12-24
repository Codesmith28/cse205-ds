#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

// class Solution {
// public:

//     bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid) {
//         if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
//             return true;
//         }
//         return false;
//     }

//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         int frsh = 0, time = 0;
//         queue<pair<int, int>>q;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == 2) {
//                     // push into queue
//                     q.push({ i, j });
//                 }
//                 else if (grid[i][j] == 1) {
//                     frsh++;
//                 }
//             }
//         }

//         // if no frsh oranges present to begin with:
//         if (frsh == 0) return 0;

//         // rottening the oranges:
//         while (!q.empty()) {

//             int sz = q.size();
//             int temp = 0;
//             while (sz != 0) {

//                 pair<int, int>p = q.front();
//                 q.pop();

//                 int x1 = p.first;
//                 int y1 = p.second;

//                 int ax[4] = { 1, -1, 0, 0 };
//                 int ay[4] = { 0, 0 , 1 , -1 };

//                 for (int i = 0; i < 4; i++) {
//                     int x = ax[i] + x1;
//                     int y = ay[i] + y1;

//                     if (isValid(x, y, n, m, grid)) {
//                         temp++;
//                         grid[x][y] = 2;
//                         q.push({ x, y });
//                     }
//                 }

//                 sz--;

//             }
//             if (temp != 0) {
//                 time++;
//             }
//         }

//         // we checked if any frsh oranges existing:
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == 1) {
//                     time = 0;
//                     break;
//                 }
//             }
//         }

//         return (time == 0) ? -1 : time;

//     }
// };

#define pii pair<int, int>

class Solution {
  public:
    vector<int> d = {0, 1, 0, -1, 0};

    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0, time = 0;

        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        auto valid = [&](int x, int y) -> bool { return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1; };

        while (!q.empty()) {
            int size = q.size();
            bool rotten = false;

            for (int i = 0; i < size; i++) {
                auto r = q.front();
                q.pop();

                int x1 = r.first, y1 = r.second;

                for (int j = 0; j < 4; j++) {
                    int x = x1 + d[j], y = y1 + d[j + 1];
                    if (valid(x, y)) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                        rotten = true;
                    }
                }
            }

            if (rotten) {
                time++;
            }
        }

        return (fresh == 0) ? time : -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << sol.orangesRotting(grid) << endl;

    return 0;
}