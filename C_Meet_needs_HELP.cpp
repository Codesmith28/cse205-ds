#include<bits/stdc++.h>
using namespace std;
#define int long long

/* (╯°□°)╯︵ ┻━┻ */

void solve()
{
    int n;
    cin >> n;

    int s;
    cin >> s;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());   
    int sum = 0;
    int ans = 0;

    for(auto it: a) {
        // if it is greater than s :
        if(it > s) {
            break;
        } else if (sum + it > s) {
            cout << ans << endl;
            return;
        } else {
            sum += it;
            ans++;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    int testCases = 1;
    // cin >> testCases;
    void solve();

    while(testCases--)
    {
        solve();
    }

    return 0;
}