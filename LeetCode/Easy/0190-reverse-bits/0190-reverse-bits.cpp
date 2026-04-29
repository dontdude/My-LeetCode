class Solution {
    // followup optimization:
    vector<int> powerOf2;

    void processPower(int s) {
        powerOf2.resize(s);
        for(int i = 0; i < s; i++) {
            powerOf2[i] = (1 << i);
        }
    }
public:
    Solution() {
        processPower(32);
    }
    int reverseBits(int n) {
        int rev = 0, s = 31;

        for(int i = 0; i <= s; i++) {
            if(n & powerOf2[i]) {
                rev = (rev | powerOf2[s - i]);
            }
        }

        return rev;
    }
};