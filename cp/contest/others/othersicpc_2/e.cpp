#include <bits/stdc++.h>
using namespace std;

/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;
int mod = 1e9 + 7;

void solve( ) {
    int l, r;
    cin >> l >> r;

    auto calc = [&](int num) -> bool {
        string s = bitset<32>(num).to_string( );
        /*s = s.substr(s.find('1'));*/

        set<int> seg;
        int n = s.size( );
        int cnt = 1;

        bool flag = false;

        for (int i = 1; i < n; i++) {
            if (!flag && s[i - 1] == '0') continue;
            flag = true;
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                seg.insert(cnt);
                cnt = 1;
            }
        }

        seg.insert(cnt);
        return seg.size( ) == 1;
    };

    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (calc(i)) cnt++;
    }

    cout << cnt << endl;
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
