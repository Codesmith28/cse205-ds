#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        map<int, int> fq;
        for (auto it : arr) {
            fq[it]++;
        }

        int ans = 0;

        for (int i = 1; i <= 10000; i++) {
            if (fq[i] == 0) {
                k--;
            }
            if (k == 0) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 2,3,4,7,11 };
    int k = 5;

    cout << s.findKthPositive(arr, k) << endl;
    return 0;
}