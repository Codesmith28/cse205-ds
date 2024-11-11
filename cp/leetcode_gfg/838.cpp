#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    string pushDominoes(string dominoes) {
        // r -> +1, l -> -1
        int n = dominoes.size( );
        string res = "";
        vector<int> forces(n, 0);

        int force = 0;
        for (int i = 0; i < n; i++) { // prefix:
            if (dominoes[i] == 'R')
                force = n;
            else if (dominoes[i] == 'L')
                force = 0;
            else
                force = max(force - 1, 0);
            forces[i] += force;
        }

        force = 0;
        for (int i = n - 1; i >= 0; i--) { // suffix:
            if (dominoes[i] == 'L')
                force = n;
            else if (dominoes[i] == 'R')
                force = 0;
            else
                force = max(force - 1, 0);
            forces[i] -= force;
        }

        for (int i = 0; i < n; i++) {
            if (forces[i] > 0)
                res += 'R';
            else if (forces[i] < 0)
                res += 'L';
            else
                res += '.';
        }
        return res;
    }
};

int main( ) {
    vector<string> tests = {"RR.L", ".L.R...LR..L.."};
    Solution sol;
    for (auto test : tests) cout << sol.pushDominoes(test) << endl;
    return 0;
}
