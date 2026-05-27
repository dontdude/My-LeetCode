class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int sumWithoutCarry = (a ^ b);
            int allCarry = (a & b) << 1;

            a = sumWithoutCarry;
            b = allCarry;
        }

        return a;
    }
};