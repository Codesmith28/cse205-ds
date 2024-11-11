#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define ll long long
class Solution {
  public:
    char kthCharacter(ll k, vector<int> &op) {  
        
    }
};

int main() {
    int k;
    cin >> k;
    int op;
    cin >> op;
    vector<int> arr(op);
    for (int i = 0; i < op; i++) cin >> arr[i];

    Solution obj;
    cout << obj.kthCharacter(k, arr) << endl;
    return 0;
}