#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;

  int l = a[0], r = a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] == l - 1)
      l = a[i];
    else if (a[i] == r + 1)
      r = a[i];
    else {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testCases = 1;
  cin >> testCases;

  while (testCases--) {
    solve();
  }

  return 0;
}