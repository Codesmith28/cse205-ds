#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void revStr(int i, int n, vector<char> &s)
    {
        if (i >= (n / 2))
        {
            return;
        }
        swap(s[i], s[n - 1 - i]);
        revStr(i + 1, n, s);
    }

    void reverseString(vector<char> &s)
    {
        int n = s.size();
        revStr(0, n, s);
    }
};

int main()
{
    return 0;
}