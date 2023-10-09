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

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // sort(begin(arr), end(arr));
        mergeSort(arr, 0, arr.size() - 1);

        int diff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            diff = min(diff, (arr[i + 1] - arr[i]));
        }

        vector<vector<int>> ans;

        for (int i = 0; i < arr.size() - 1; i++) {
            int a = arr[i];
            int b = arr[i + 1];

            vector<int> temp;
            if ((b - a) == diff) {
                temp.push_back(a);
                temp.push_back(b);

                ans.push_back(temp);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = { 4,2,1,3 };
    vector<vector<int>> ans = sol.minimumAbsDifference(arr);

    for (auto it : ans) {
        for (auto it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}