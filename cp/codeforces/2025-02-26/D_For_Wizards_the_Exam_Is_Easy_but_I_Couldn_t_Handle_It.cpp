#include <bits/stdc++.h>
using namespace std;

/* (╯°□°)╯︵ ┻━┻ */

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int l = 0, r = 0, diff = 0;

    for (int i = 0; i < n; i++) {
        int more = 0, less = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j])
                less++;
            else if (a[i] > a[j])
                more++;
            int cdiff = less - more;
            if (cdiff < diff) {
                diff = cdiff;
                l = i;
                r = j;
            }
        }
    }

    cout << l + 1 << " " << r + 1 << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}