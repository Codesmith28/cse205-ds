#include<bits/stdc++.h>
using namespace std;


// approach recursive:
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<int> sub;
        vector<vector<int>> all;

        // all possible subsets: 0 to (2^n -1)
        for(int i=0; i<(1<<n); i++) {

            // clear the working subset for the new subsets:
            sub.clear();

            // all indicies from the nums
            for(int j=0; j<n; j++){
                
                // only those combinations will be fit where the bits match 
                if ((i & (1 << j)) != 0) {
                    sub.push_back(nums[j]);
                }
            }

            all.push_back(sub);
        }

        return all;
    }
};

int main()
{

    return 0;
}