#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        m--;
        n--;

        int r = min(m, n);
        int N = m + n;

        // now since calculating nCr directly gives integer overflow...
        // we will calculate it using following:

        // nCr = prod((n-r+i)/i) for i in [1,r]
        int ans = 1;
        for (int i = 1; i <= r; i++)
        {

            int Nr = (N - r + i);
            int Dr = i;

            ans *= (Nr / Dr);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(4, 4) << endl;
    return 0;
}