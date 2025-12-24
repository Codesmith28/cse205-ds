#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int, vector<int>> pqo;
        priority_queue<int, vector<int>> pqe;

        string a = to_string(num);

        for (auto it : a) {
            if ((it - '0') % 2 == 0) {
                pqe.push(it);
            }
            else {
                pqo.push(it);
            }
        }

        string b;

        for (auto it : a) {
            if ((it - '0') % 2 == 0) {
                b += pqe.top();
                pqe.pop();
            }
            else {
                b += pqo.top();
                pqo.pop();
            }
        }

        return stoi(b);
    }
};

int main() {

    return 0;
}