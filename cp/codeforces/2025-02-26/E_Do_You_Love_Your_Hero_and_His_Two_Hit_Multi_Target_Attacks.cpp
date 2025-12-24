#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;
    
public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    
    void update(int index, int value) {
        while (index <= n) {
            tree[index] += value;
            index += index & -index;
        }
    }
    
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};

int countInversions(const vector<int>& arr, int n) {
    // Compress the array values using coordinate compression
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    // Remove duplicates for mapping
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());
    unordered_map<int, int> rank;
    int rankVal = 1;
    for (int val : sortedArr) {
        rank[val] = rankVal++;
    }
    
    // Fenwick Tree size is the number of unique values
    FenwickTree ft(rank.size());
    long long inversions = 0;
    
    // Process array from right to left
    for (int i = n - 1; i >= 0; --i) {
        int r = rank[arr[i]];
        // Query number of elements less than r that we've seen so far
        // Elements to the left and greater than arr[i] form inversions
        inversions += ft.query(r - 1);
        // Update the tree
        ft.update(r, 1);
    }
    return inversions;
}

void solve(int n, const vector<int>& a) {
    long long minInversions = LLONG_MAX;
    pair<int, int> bestLR = {1, 1};
    
    // Try all possible l and r
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            // Create a copy of the array and perform the shift
            vector<int> b = a;
            if (l < r) {
                // Perform left cyclic shift on [l, r]
                // Save a[l-1] (since indices in array are 0-based)
                int temp = b[l - 1];
                // Shift elements from l to r-1
                for (int k = l; k < r; ++k) {
                    b[k - 1] = b[k];
                }
                // Place a[l] at position r
                b[r - 1] = temp;
            }
            // Compute inversions in the modified array
            long long inv = countInversions(b, n);
            if (inv < minInversions) {
                minInversions = inv;
                bestLR = {l, r};
            }
        }
    }
    
    cout << bestLR.first << " " << bestLR.second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve(n, a);
    }
    
    return 0;
}