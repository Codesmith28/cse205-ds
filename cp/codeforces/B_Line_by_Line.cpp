#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve(int tc) {
    int n, p;
    cin >> n >> p;

    double prob = p / 100.0;
    double pnew = pow(prob, (n - 1.0) / n) * 100.0;
    double res = pnew - p;

    cout << "Case #" << tc << ": " << fixed << setprecision(15) << res << endl;
}

int32_t main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        solve(i + 1);
    }
    return 0;
}
