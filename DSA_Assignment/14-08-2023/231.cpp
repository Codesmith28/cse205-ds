class Solution {
public:
    bool isPowerOfTwo(int n) {

        // non recursive approach:
        // // n & n-1 will always give 0 for n which will be a power of 2;
        // // return (!(n & n-1));
        // // for the edge case of 0:
        // if(n<=0){
        //     return false;
        // }
        // return !(n & n-1);


        // recursive approach:
        if(n==1){
            return true;
        }
        
        if(n%2 != 0 or n==0){
            return false;
        }

        return isPowerOfTwo(n/2);
    }
};