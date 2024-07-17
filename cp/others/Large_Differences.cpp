#include <bits/stdc++.h>
#include <vector>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

// Function to compute the initial sum of adjacent differences
int initialSum(vector<int> &A) {
    int sum = 0;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        sum += abs(A[i] - A[i + 1]);
    }
    return sum;
}

int mxAdj(vector<int> &A, int K) {
    int N = A.size();
    int initial = initialSum(A);
    int mx = initial;

    for (int i = 0; i < N; ++i) {
        // Calculate the original sum of differences involving A[i]
        int old = (i > 0) ? abs(A[i] - A[i - 1]) : 0;
        int ord = (i < N - 1) ? abs(A[i] - A[i + 1]) : 0;
        int ods = old + ord;

        // Calculate new sum of differences if A[i] is set to 1
        int nld = (i > 0) ? abs(1 - A[i - 1]) : 0;
        int nrd = (i < N - 1) ? abs(1 - A[i + 1]) : 0;
        int nds = nld + nrd;

        // Calculate new sum of differences if A[i] is set to K
        int nldk = (i > 0) ? abs(K - A[i - 1]) : 0;
        int nrdk = (i < N - 1) ? abs(K - A[i + 1]) : 0;
        int ndsk = nldk + nrdk;

        // Update the max sum based on the changes
        int nsum1 = initial - ods + nds;
        int nsumk = initial - ods + ndsk;

        mx = max({mx, nsum1, nsumk});
    }

    return mx;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    cout << mxAdj(a, k) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}