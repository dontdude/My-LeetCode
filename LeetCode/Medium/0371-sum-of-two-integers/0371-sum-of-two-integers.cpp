class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int sumWithoutCarry = (a ^ b);  // xor is sum without carry
            int carry = (a & b) << 1; // carry always adds to next num

            a = sumWithoutCarry;
            b = carry;
        }

        return a;
    }
};