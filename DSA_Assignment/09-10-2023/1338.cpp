#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        for (auto it : arr) {
            mp[it]++;
        }

        if (mp.size() == 1) {
            return 1;
        }

        vector<pair<int, int>> fqq;
        for (auto it : mp) { // Change "fq" to "mp" here
            fqq.push_back({ it.second, it.first }); // Correct the order of elements in the pair
        }

        int fq = 0;
        int n = arr.size();
        int ans = 0;

        sort(rbegin(fqq), rend(fqq));

        for (auto it : fqq) {
            ans++;
            fq += it.first;
            if (fq >= n / 2) { // Check if we've removed enough elements
                break;
            }
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    vector<int> arr = { 3, 3, 3, 3, 5, 5, 5, 2, 2, 7 };
    cout << sol.minSetSize(arr) << endl;

    return 0;
}