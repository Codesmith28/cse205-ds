#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'
const int mod = 1000000007;
// clang-format off
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// clang-format on
 
void solve()
{
    ll t, m, n, a, k, d;
    string h;
    cin >> n >> k >> d;
    vector<int> v(n);
    vector<int> b(k);
    cin >> v;
    cin >> b;
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
    {
        diff[i] = v[i] - (i + 1);
    }
    int ans = count(diff.begin(), diff.end(), 0);
    dbg(diff);
    int anss = ans + (d - 1) / 2;
    dbg(anss);
    for (int i = 0; i < min(d - 1, 2 * n); i++)
    {
        int temp = ans;
        for (int j = 0; j < b[i % b.size()]; j++)
        {
            diff[j]++;
            if (diff[j] == 1)
                temp--;
            else if (diff[j] == 0)
                temp++;
        }
        dbg(i, diff);
        ans = temp;
        // if (d - i - 2 >= 0)
        {
            temp = ans + (d - i - 2) / 2;
            anss = max(anss, temp);
        }
    }
    cout << anss << endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}