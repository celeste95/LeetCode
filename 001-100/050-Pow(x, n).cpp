class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) 
        {
            if(n == INT_MIN) return 1.0/ (myPow(x, INT_MAX) * x);
            else return 1.0/myPow(x, -n);
        }
        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
    }
};