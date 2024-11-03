class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 )  return 1;

        int power = abs(n) / 2;
        double curr = myPow(x, power);
        double res = curr * curr;
        if(n & 1) {
            res *= x;
        }

        return n < 0 ? 1 / res : res;
    }
};