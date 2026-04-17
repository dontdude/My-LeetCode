class Solution {
    bool isSafe(int num, int digit, int limit) {
        int truncatedDigit = limit % 10;
        int restLimit = limit / 10;
        if(limit == INT_MIN)  return num > restLimit || (num == restLimit && digit >= truncatedDigit);
        return num < restLimit || (num == restLimit && digit <= truncatedDigit);
    }
public:
    int reverse(int x) {
        int limit = (x > 0) ? INT_MAX : INT_MIN;
        int revx = 0, sign = 1;

        while(x) {
            int d = x % 10;
            x /= 10;

            if(isSafe(revx, d, limit) == false) {
                return 0; 
            } 

            revx *= 10;
            revx += d;
        }

        return revx;
    }
};