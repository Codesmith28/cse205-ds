#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> left(n1);
        vector<int> right(n2);

        // Copy data to temporary arrays left[] and right[]
        for (int i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            right[j] = arr[mid + 1 + j];
        }

        // Merge the two subarrays back into the original array arr[]
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of left[], if any
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }

        // Copy the remaining elements of right[], if any
        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);

            // Merge the sorted halves
            merge(arr, l, mid, r);
        }
    }

    int majorityElement(vector<int>& nums) {
        // map<int, int>fq;
        // for(int it: nums) {
        //     fq[it]++;
        // }

        // int mxFreq = 0;
        // int mxEle = 0;

        // for(auto it: fq) {
        //     if(it.second > mxFreq) {
        //         mxFreq = it.second;
        //         mxEle = it.first;
        //     }
        // }

        // return mxEle;

        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums[n / 2];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 2,2,1,1,1,2,2 };
    cout << sol.majorityElement(nums) << endl;

    return 0;
}