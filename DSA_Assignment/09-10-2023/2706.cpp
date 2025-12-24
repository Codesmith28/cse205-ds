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

    int buyChoco(vector<int>& prices, int money) {
        mergeSort(prices, 0, prices.size() - 1);

        int sum = prices[0] + prices[1];
        return (sum > money ? money : money - sum);
    }
};

int main()
{
    Solution sol;
    vector<int> prices = { 1, 2, 3, 4, 5 };
    int money = 6;

    int ans = sol.buyChoco(prices, money);
    cout << ans << endl;

    return 0;
}