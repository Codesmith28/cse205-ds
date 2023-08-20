#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:

    string maker(int n) {
        
        // base case:
        if(n == 1) {
            return "1";
        }
        
        string prev = maker(n-1);
        char curr = prev[0];
        int currCount = 1;

        string response = "";

        for(int i=1; i<prev.size(); i++) {
            if(prev[i] != curr) {
                response += to_string(currCount) + curr;
                currCount = 1;
                curr = prev[i];
            }
            else {
                currCount++;
            }
        }

        response += to_string(currCount) + curr;
        return response;
    }

    string countAndSay(int n) {
        string ans = maker(n);
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.countAndSay(4) << endl;
    
    return 0;
}