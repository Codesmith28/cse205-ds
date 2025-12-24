#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    auto set_bit_arr = [&](int num, vector<int> &arr) -> void {
        int i = 0;
        while (num) {
            if (num % 2) arr[i]++;
            num /= 2;
            i++;
        }
    };

    auto unset_bit_arr = [&](int num, vector<int> &arr) -> void {
        int i = 0;
        while (num) {
            if (num % 2) arr[i]--;
            num /= 2;
            i++;
        }
    };

    auto is_lonely = [&](int k) -> bool {
        vector<int> bitfq(32, 0);
        for (int i = 0; i < k; i++) {
            set_bit_arr(a[i], bitfq);
        }

        vector<int> frq = bitfq;
        for (int i = k; i < n; i++) {
            set_bit_arr(a[i], frq);
            unset_bit_arr(a[i - k], frq);

            for (int i = 0; i < 32; i++) {
                if (frq[i] > 0 && bitfq[i] == 0) return false;
                if (frq[i] == 0 && bitfq[i] > 0) return false;
            }
        }

        return true;
    };

    int k = n;
    int l = 1, r = n;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (is_lonely(mid)) {
            k = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << k << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
