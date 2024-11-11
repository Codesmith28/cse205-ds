#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long minPresses(vector<int> &a, int k) {
        int n = a.size( );
        long long sum = 0;
        for (int x : a) sum += x;

        long long left = k, right = sum;

        auto check = [&](long long presses) {
            vector<int> b = a;
            sort(b.begin( ), b.end( ));
            long long cans = 0;
            for (int i = 0; i < n; i++) {
                cans += min((long long)b[i], presses / (n - i));
                presses -= min((long long)b[i], presses / (n - i));
            }
            return cans >= k;
        };

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

// Main function for testing
int main( ) {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution sol;
        cout << sol.minPresses(a, k) << endl;
    }

    return 0;
}
