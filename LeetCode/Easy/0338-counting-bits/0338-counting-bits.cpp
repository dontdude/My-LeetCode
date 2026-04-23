class Solution {
    int setBitCount(int num) {
        int bit = 0;
        while(num) {
            num &= (num - 1);
            bit++;
        }

        return bit;
    }
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for(int i = 0; i <= n; i++) {
            bits[i] = setBitCount(i);
        }

        return bits;
    }
};