#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char it : s) {
            if (it == '(' or it == '{' or it == '[') {
                st.push(it);
            }

            else {
                if (st.empty()) {
                    return false;
                }
                if (it == ']' and st.top() == '[') {
                    st.pop();
                }
                else if (it == ')' and st.top() == '(') {
                    st.pop();
                }
                else if (it == '}' and st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    string s = "()";
    cout << sol.isValid(s) << endl;

    return 0;
}