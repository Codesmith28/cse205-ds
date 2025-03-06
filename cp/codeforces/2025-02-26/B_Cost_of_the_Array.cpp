#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) (v).begin( ), (v).end( )

void solve( ) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin( ), a.end( ), greater<int>( ));

    vector<vector<int>> subarrays(k);
    for (int i = 0; i < n; i++) {
        subarrays[i % k].push_back(a[i]);
    }

    vector<int> b;
    for (int i = 1; i < k; i += 2) { // Concatenating even-indexed subarrays
        b.insert(b.end( ), all(subarrays[i]));
    }
    b.push_back(0); // Appending 0 at the end

    int cost = 1;
    for (int x : b) {
        if (x != cost) break;
        cost++;
    }

    cout << cost << "\n";
}

int main( ) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve( );
    }
    return 0;
}