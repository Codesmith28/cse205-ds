#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second

#define all(x) x.begin(),x.end()
#define pb push_back
#define pf push_front

#define pq priority_queue<int, vi>
#define pqg priority_queue<int, vi, greater<int> >
#define mls multiset

#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define endl '\n'

#define minE(x) *min_element(all(x))
#define maxE(x) *max_element(all(x))
#define rev(x) reverse(all(x))

// decimal to binary
string toBin(int value) {
    string r = "";
    while (value) r = (value % 2 ? "1" : "0") + r, value /= 2;
    return r;
}

//last digit (x^n) 
int lastDigit(int x, int n)
{
    int cycle[4];
    cycle[0] = x%10;
    rep(i,1,4)
    {
        cycle[i] = ( cycle[i-1] * cycle[0] ) % 10;
    }
    return (n == 0 ? 1 : cycle[(n - 1) % 4]);
}

void solve()
{
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin>>testCases;
    // cout << setprecision(10) << fixed;
    while (testCases--) {
        solve();
    }
    return 0;
}