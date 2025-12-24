#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        for (int j = l; j <= r; j++)
        {
            mp[j]++;
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        int ans = 0;
        for (int i = a; i <= b; i++)
        {
            if (mp[i] >= k)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }
}

int32_t main()
{
    int testCases = 1;
    // cin >> testCases;
    void solve();

    while (testCases--)
    {
        solve();
    }

    return 0;
}