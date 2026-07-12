class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if(n == 1 && (s1[0] == '1' && s2[0] == '0'))  return -1;   // 1 has nothing to pair with

        int opr = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                if(s1[i] == '0') {
                    opr++;
                    s1[i] = '1';
                } else if(s1[i] == '1') {
                    if(i < n - 1) {  // 1 at i can pair with next
                        if(s1[i + 1] == '1')  opr += 1;
                        else opr += 2;

                        s1[i] = '0';
                        s1[i + 1] = '0';   // i + 1 changed, which will later get fixed if required, in next iteration
                    } else {      // 1 has nothing in next to pair with, so it pairs with prev, since prev was already fine, so we try to keep prev i - 1 value as it is, which in both (01->00) or (11->10) case requires 2 operations
                        opr += 2;
                        s1[i] = '0';
                    }
                }
            } 
        }

        return opr;
    }
};