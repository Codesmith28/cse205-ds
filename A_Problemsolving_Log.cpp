#include <bits/stdc++.h>
using namespace std;

/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    unordered_map<char, int> mp;
    for (char x = 'A'; x <= 'Z'; x++)
    {
        mp[x] = x - 'A' + 1;
    }

    for (char &c : s)
    {
        mp[c]--;
    }

    for (auto it : mp)
    {
        if (it.second <= 0)
        {
            ans++;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    int testCases = 1;
    cin >> testCases;

    while (testCases--)
    {
        solve();
    }

    return 0;
}