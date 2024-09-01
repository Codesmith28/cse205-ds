#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>> &img, int sr, int sc, int color) {
        int n = img.size(), m = img[0].size();
        int col = img[sr][sc];

        auto dfs = [&](int r, int c, auto &&dfs) -> void {
            if (img[r][c] == col) {
                img[r][c] = color;

                if (r >= 1) dfs(r - 1, c, dfs);
                if (c >= 1) dfs(r, c - 1, dfs);
                if (r + 1 < n) dfs(r + 1, c, dfs);
                if (c + 1 < m) dfs(r, c + 1, dfs);
            }
        };

        if (col != color) dfs(sr, sc, dfs);
        return img;
    }
};

int main() {
    return 0;
}