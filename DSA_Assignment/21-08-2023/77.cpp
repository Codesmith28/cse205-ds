#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    void maker(vector<vector<int>> &ans, vector<int> &temp, int it, int n, int k)
    {

        // when the group size is completed then put the list into the answer
        if (k == 0)
        {
            ans.push_back(temp);
        }

        // start inserting the numbers from it to n:
        for (int i = it; i <= n; i++)
        {
            // insert i:
            temp.push_back(i);
            // call for other elements after i and before n:
            maker(ans, temp, i + 1, n, k - 1);
            // remove the element 'i' from the temp and move to the next one:
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int it = 1; // for the number from 1 to n

        maker(ans, temp, it, n, k);
        return ans;
    }
};

int main()
{
    Solution sol;

    int n = 4;
    int k = 2;
    vector<vector<int>> ans = sol.combine(n, k);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}