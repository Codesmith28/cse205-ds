#include <bits/stdc++.h>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int maxScore(vector<vector<int>> &grid) {
        for (auto &it : grid) it.push_back(0);
        for (auto &it : grid) sort(begin(it), end(it), greater<int>());
        sort(grid.begin(), grid.end(), [](vector<int> &a, vector<int> &b) { return a[0] > b[0]; });

        // Create a set to track unique elements
        set<int> uniqueElements;

        // Add elements to the set and calculate their sum
        int totalSum = 0;
        for (const auto &row : grid) {
            for (int value : row) {
                if (uniqueElements.find(value) == uniqueElements.end()) {
                    uniqueElements.insert(value);
                    totalSum += value;
                }
            }
        }

        return totalSum;
    }
};

int main() {
    Solution s;
    /*
    [[5],[7],[19],[5]]
    [[5,5],[5,5],[11,5]]
    [[12,12],[4,4],[12,12]]
    [[14,5],[11,2],[2,11]]
    [[12],[12],[12],[11]]
    */
    vector<vector<vector<int>>> tc = {
        {{5}, {7}, {19}, {5}},
        {{5, 5}, {5, 5}, {11, 5}},
        {{12, 12}, {4, 4}, {12, 12}},
        {{14, 5}, {11, 2}, {2, 11}},
        {{12}, {12}, {12}, {11}}
    };

    int i = 1;
    for (auto &t : tc) {
        cout << s.maxScore(t) << endl;
    }
    return 0;
}