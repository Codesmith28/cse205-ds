#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

int alicelis(int A[], int N) {
    int count = 1;
    int last = A[1];
    for (int i = 2; i <= N; i++) {
        if (A[i] > last) {
            count++;
            last = A[i];
        }
    }
    return count;
}

void solve() {
    int n, x;
    cin >> n >> x;

    

}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}