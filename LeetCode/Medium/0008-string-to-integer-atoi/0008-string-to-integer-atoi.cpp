class Solution {
    bool isDigit(char c) {
        int digit = c - '0';
        return digit >= 0 && digit <= 9;
    }
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        int sign = 1;
        long long base = 0;

        while(i < n && s[i] == ' ')  i++;

        if(i < n && s[i] == '-' or s[i] == '+') {
            if(s[i] == '-')  sign = -1;
            i++;
        }

        while(i < n && s[i] == '0')  i++;

        while(i < n && isDigit(s[i])) {
            base = base * 10 + (s[i] - '0');

            if(sign * base >= INT_MAX) {
                return INT_MAX;
            } else if(sign *  base <= INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * base;
    }
};