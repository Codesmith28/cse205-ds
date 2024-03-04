#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (auto op : ops) {
            if (op == "+") {
                int top = st.top();
                st.pop();
                int newtop = top + st.top();
                st.push(top);
                st.push(newtop);
            }
            else if (op == "C") {
                st.pop();
            }
            else if (op == "D") {
                st.push(2 * st.top());
            }
            else {
                st.push(stoi(op));
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    vector<string> ops = { "5","-2","4","C","D","9","+","+" };

    cout << sol.calPoints(ops) << endl;
    return 0;
}