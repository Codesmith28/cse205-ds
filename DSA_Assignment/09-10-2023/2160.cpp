#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:

    void bubbleSort(vector<int>& arr)
    {
        int n = arr.size();

        int i, j;
        bool swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            // If no two elements were swapped
            // by inner loop, then break
            if (swapped == false)
                break;
        }
    }

    int minimumSum(int num) {

        vector<int> dig;
        while (num) {
            int r = num % 10;
            dig.push_back(r);
            num = num / 10;
        }

        bubbleSort(dig);

        string a, b;

        for (int i = 0; i < 4; i++) {
            string x = to_string(dig[i]);
            i % 2 == 0 ? a += x : b += x;
        }

        return stoi(a) + stoi(b);
    }
};

int main()
{
    Solution sol;
    int num;
    cin >> num;

    cout << sol.minimumSum(num) << endl;
    return 0;
}