class Solution {
public:

    int nthFib(int n){
        if(n==1 or n==0){
            return n;
        }
        return nthFib(n-1) + nthFib(n-2);
    }

    int fib(int n) {
        return nthFib(n);
    }
};