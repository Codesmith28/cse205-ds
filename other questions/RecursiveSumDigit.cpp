#include <bits/stdc++.h>
using namespace std;

string summer(string s) {

    if (s.length() == 1) {
        return s;
    }

    int ans = 0;
    for (auto it : s) {
        ans += it - '0';
    }

    s = to_string(ans);
    return summer(s);
}

int main()
{
    int n, k;
    cin >> n >> k;

    string s = "";
    while (k--) {
        s += to_string(n);
    }

    cout << stoi(summer(s)) << endl;
    return 0;
}