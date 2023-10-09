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

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> count_map;

        // Count the occurrences of each element in arr1
        for (int num : arr1) {
            count_map[num]++;
        }

        vector<int> ans;

        // Iterate through arr2 to maintain relative order
        for (int num : arr2) {
            int count = count_map[num];
            for (int i = 0; i < count; i++) {
                ans.push_back(num);
            }
            count_map.erase(num); // Remove the processed element from the map
        }

        // Append the remaining elements from arr1 in ascending order
        vector<int> rem;
        for (auto entry : count_map) {
            for (int i = 0; i < entry.second; i++) {
                rem.push_back(entry.first);
            }
        }

        // Sort the remaining elements
        // sort(rem.begin(), rem.end());
        mergeSort(rem, 0, rem.size() - 1);

        // Append the sorted remaining elements to the result
        ans.insert(ans.end(), rem.begin(), rem.end());

        return ans;
    }
};


int main()
{
    Solution sol;
    vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
    vector<int> arr2 = { 2,1,4,3,9,6 };

    vector<int> ans = sol.relativeSortArray(arr1, arr2);

    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}