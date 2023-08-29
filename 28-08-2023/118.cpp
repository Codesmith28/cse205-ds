#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int>> ans;
        vector<int> first = { 1 };
        vector<int> second = { 1, 1 };

        ans.push_back(first);
        if (n == 1) {
            return ans;
        }

        ans.push_back(second);
        if (n == 2) {
            return ans;
        }

        for (int i = 3; i <= n; i++) {
            vector<int> temp;
            temp.push_back(1);  // The first element in each row is always 1.

            // size of sandwich stuff = size of stuff 2 rows before:
            for (int j = 1; j < ans[i - 2].size(); j++) {
                temp.push_back(ans[i - 2][j - 1] + ans[i - 2][j]);
            }

            temp.push_back(1);  // The last element in each row is always 1.
            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    int n = 5;

    vector<vector<int>> ans = s.generate(n);

    for (auto it : ans) {
        for (auto it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}