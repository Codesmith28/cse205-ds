#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int x;
    cin >> x;

    // Convert the number to binary
    bitset<32> b(x);
    vector<int> num(32);
    for (int i = 0; i < 32; i++) num[i] = b[i];

    int carry = 0;

    for (int i = 0; i < 31; i++) {
        if (carry == 1) {
            if (num[i] == 1) {
                num[i] = 0;
                carry = 1;
            } else if (num[i] == 0) {
                num[i] = 1;
                carry = 0;
            } else if (num[i] == -1) {
                num[i] = 0;
                carry = 0;
            }
        } else if (carry == -1) {
            if (num[i] == 1) {
                num[i] = 0;
                carry = 0;
            } else if (num[i] == 0) {
                num[i] = -1;
                carry = 0;
            } else if (num[i] == -1) {
                num[i] = 0;
                carry = -1;
            }
        }

        if (num[i] == num[i + 1] && num[i] != 0) {
            if (num[i] == 1) {
                num[i] = -1;
                carry = 1;
            } else if (num[i] == -1) {
                num[i] = 1;
                carry = -1;
            }
        }
    }

    // get msb:
    int msb = 31;
    for (int i = 31; i >= 0; i--) {
        if (num[i] != 0) {
            msb = i;
            break;
        }
    }
    int len = msb + 1;
    cout << len << endl;
    for (int i = 0; i < len; i++) cout << num[i] << " ";
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
