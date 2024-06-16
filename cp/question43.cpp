#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int a = num1.size();
        int b = num2.size();

        int place = 1, digit = 1, carry = 0;
        int temp = 0;
        int ans = 0;

        // for the digit wise multiplication using nested for loop:
        for (int i = a - 1; i >= 0; i--)
        {
            temp = 0;
            for (int j = b - 1; j >= 0; j--)
            {
                temp += (num1[i] * num2[j]) * digit + carry;
                digit *= 10;
                carry = (num1[i] * num2[j]) / 10;
            }
            ans += temp * 10;
            place *= 10;
        }
    }
};

int main()
{

    Solution s;
    string num1 = "123";
    string num2 = "456";
    cout << s.multiply(num1, num2) << endl;
    return 0;
}