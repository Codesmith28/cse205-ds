#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        map<int, int> idx;
        for (int i = 0; i < n; i++) {
            idx[nums1[i]] = i;
        }

        vector<int> ans(n, -1);

        stack<int> st;

        for (auto curr : nums2) {
            while (!st.empty() and curr > st.top()) {
                int val = st.top();
                st.pop();
                int pos = idx[val];
                ans[pos] = curr;
            }

            if (idx.find(curr) != idx.end()) {
                st.push(curr);
            }
        }

        return ans;
    }
};


// normal approach:
/* class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        map<int, int> idx;
        for(int i=0; i<n; i++) {
            idx[nums1[i]] = i;
        }

        vector<int> ans(n, -1);

        for (int i=0; i<m; i++) {

            // if the numebr is not present in the mapping:
            if( idx.find(nums2[i]) == idx.end() ) {
                continue;
            }

            for (int j=i+1; j<m; j++) {
                if(nums2[j] > nums2[i]) {
                    int x = idx[nums2[i]];
                    ans[x] = nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
}; */

int main()
{
    Solution sol;
    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };

    vector<int> ans = sol.nextGreaterElement(nums1, nums2);

    return 0;
}