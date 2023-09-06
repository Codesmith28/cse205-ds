#include<bits/stdc++.h>
using namespace std;
#define int long long

/* (╯°□°)╯︵ ┻━┻ */

void solve()
{
    int a, s;
    cin >> a >> s;
    
    int diff = s - a;

    string num1 = to_string(diff);
    string num2 = to_string(a);

    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());

    cout << (num1==num2 ? "YES\n" : "NO\n");
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