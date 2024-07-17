#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

bool isVowel(char c) {
    return (c == 'a' || c == 'e');
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // split the given string in syllables which are separated by a ".: and then print that string
    // a syllabel is CV or CVC whre C is a consonant and V is a vowel

    vector<string> syllables;
    string temp = "";

    for (int i = 0; i < n; i++) {
        char x = s[i];
        temp += x;

        if (isVowel(x)) {

            if (i + 1 < n && !isVowel(s[i + 1])) {
                if (i + 2 < n && isVowel(s[i + 2])) {
                    syllables.push_back(temp);
                    temp = "";
                }
                else {
                    temp += s[i + 1];
                    syllables.push_back(temp);
                    temp = "";
                    i++;
                }
            }
            else {
                continue;
            }
        }
    }

    if (temp != "") {
        syllables.push_back(temp);
    }

    for (int i = 0; i < syllables.size() - 1; i++) {
        cout << syllables[i] << ".";
    }
    cout << syllables[syllables.size() - 1] << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}