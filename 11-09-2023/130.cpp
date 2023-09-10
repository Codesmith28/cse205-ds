#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */


int main()
{
    vector<vector<char>> board = { {'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'} };

    for (auto it : board) {
        for (auto x : it) {
            cout << x << " ";
        }
        cout << endl;
    }


    return 0;
}