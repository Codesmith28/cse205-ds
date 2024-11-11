#include <bits/stdc++.h>
#include <iterator>
#include <unordered_map>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int getMinimumCost(vector<int> &machineCount, vector<int> &finalMachineCount, int shifitingCost) {
        sort(begin(machineCount), end(machineCount));
        sort(begin(finalMachineCount), end(finalMachineCount));
        int ans = 0, i = 0, j = 0;

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> machineCount = {
        {2, 4, 5, 3},
        {5, 10, 15, 20, 25},
        {2, 3, 5, 7}
    };
    vector<vector<int>> finalMachineCount = {
        {4,  4,  4 },
        {20, 20, 20},
        {5,  10, 5 }
    };
    vector<int> shifitingCost = {1, 3, 2};

    for (int i = 0; i < machineCount.size(); i++) {
        cout << s.getMinimumCost(machineCount[i], finalMachineCount[i], shifitingCost[i]) << endl;
    }

    return 0;
}
