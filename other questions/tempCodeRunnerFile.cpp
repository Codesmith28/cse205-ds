#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int a = num1.size();
        int b = num2.size();
        int ans = 0;
        // for loop for the digits in the second number?

        int temp = 0;
        int digit = 1;
        int carry = 0;

        int place = 1;

        for(int i=b-1; i>=0; i--){

            temp = 0;
            digit = 1;
            for(int j=a-1; j>=0; j--){
                temp = digit * (num1[j]-'0')*(num2[j]-'0') + carry;
                carry = temp/10;
                digit *= 10;
            }
            ans += temp * place;
            place *= 10;
        }

        // convert the ans to string
        string res = "";
        while(ans){
            res += (ans%10) + '0';
            ans /= 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){

    Solution s;
    string num1 = "123";
    string num2 = "456";
    cout<<s.multiply(num1, num2)<<endl;
    return 0;
}