#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int sumOfMultiples(int n) {

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
                ans += i;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    int n = 10;
    cout << s.sumOfMultiples(n) << endl;

    return 0;
}