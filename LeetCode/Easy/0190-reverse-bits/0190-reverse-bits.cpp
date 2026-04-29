class Solution {
public:
    int reverseBits(int n) {
        int rev = 0, s = 31;

        for(int i = 0; i <= s; i++) {
            if(n & (1 << i)) {
                rev = (rev | (1 << (s - i)));
            }
        }

        return rev;
    }
};