#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<int> fq(n);
        for (int i = 0; i < roads.size( ); i++) {
            sort(roads[i].begin( ), roads[i].end( ));
            fq[roads[i][0]]++;
            fq[roads[i][1]]++;
        }

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = fq[i];
                int b = fq[j];

                int temp = a + b;

                // Check if there is a road between city i and city j
                // bool connected = false;

                for (int k = 0; k < roads.size( ); k++) {
                    if ((roads[k][0] == i && roads[k][1] == j)) {
                        // connected = true;
                        temp--;
                        break;
                    }
                }

                ans = max(ans, temp);

                // if (connected) {
                //     ans = max(ans, a + b - 1);  // If they are related by a road
                // } else {
                //     ans = max(ans, a + b);  // If they are not related by a road
                // }
            }
        }

        return ans;
    }
};

int main( ) {
    Solution sol;
    vector<vector<int>> roads = {
        {0, 1},
        {0, 3},
        {1, 2},
        {1, 3}
    };
    int n = 4;

    cout << sol.maximalNetworkRank(n, roads) << endl;

    return 0;
}
