#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }

    bool allEqual = true;
    for (int i = 1; i < n; i++) {
        if (C[i] != C[0]) {
            allEqual = false;
            break;
        }
    }

    if (allEqual) {
        for (int i = 0; i < n; i++) cout << A[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++) cout << B[i] << " ";
        cout << endl;
    }

    else {
        cout << -1 << endl;
    }
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}