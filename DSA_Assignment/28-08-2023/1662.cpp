#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";

        for (auto it : word1) {
            a += it;
        }

        for (auto it : word2) {
            b += it;
        }

        return a == b;
    }
};

int main()
{
    Solution s;
    vector<string> word1 = { "ab", "c" };
    vector<string> word2 = { "a", "bc" };

    cout << s.arrayStringsAreEqual(word1, word2) << endl;
    return 0;
}