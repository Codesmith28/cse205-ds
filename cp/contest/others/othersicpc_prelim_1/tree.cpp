/*
    This solution is written by Utsav_11
    Name: Utsav Raithatha
    Created on: 2024-11-16 at 19:02
*/

#include <bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define dbg(x...)
// #endif

#define FIO                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            \
    ios_base::sync_with_stdio(false);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  \
    cin.tie(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        \
    cout.tie(0)
#define ll long long
#define pb push_back

void solve( ) {
    ll n, d, l;
    cin >> n >> d >> l;

    if (l >= n) {
        cout << -1 << endl;
        return;
    }

    ll left = 2 * ((n - 1) / l) + min(2ll, ((n - 1) % l));
    ll right = (n - 1 - (l - 2));

    // cout << left << " " << right << endl;

    ll node = 2 + l;

    if (d >= left && d <= right) {
        for (ll i = 0; i < l; i++) {
            cout << 1 << " " << i + 2 << endl;
        }

        ll turn = 0;
        for (ll i = 3; i <= d; i++) {
            if (turn == 0) {
                cout << 2 << " " << node << endl;
            } else {
                cout << 3 << " " << node << endl;
            }
            node++;
            turn = !turn;
        }

        turn = 4;
        vector<ll> prev(l + 4);
        for (ll i = 0; i <= l + 4; i++) {
            prev[i] = i;
        }

        while (node <= n) {
            cout << prev[turn] << " " << node << endl;
            prev[turn] = node;
            turn++;
            node++;

            if (turn == l + 2) {
                turn = 4;
            }
        }
    } else {
        cout << -1 << endl;
    }
}

int main( ) {
    FIO;
    int t = 1;
    cin >> t;

    while (t--) {
        solve( );
    }

    return 0;
}
