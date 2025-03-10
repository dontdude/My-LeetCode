class Solution {
public:
    int myAtoi(string s) {
        int res = 0, i = 0, sign = 1;
        while(s[i] == ' ')  i++;

        if(s[i] == '-' || s[i] == '+') {
            sign *= (s[i++] == '-') ? -1 : 1;
        }

        while(s[i] >= '0' && s[i] <= '9') {
            int INT_MAX_10 = INT_MAX / 10;
            if(res > INT_MAX_10 || (res == INT_MAX_10) && (s[i] - '0' > 7)) {       
                if(sign > 0) return INT_MAX;  //2147483647
                else return INT_MIN;  //-2147483648
            }
            res = 10 * res + (s[i++] - '0');
        }

        return res * sign;
    }
};