class Solution {
    long long modularExponentiation(int base, int exponent, int mod) {
        if(exponent == 0) return 1LL;
        if(exponent == 1) return (long long)base;

        long long halfExpo = modularExponentiation(base, exponent / 2, mod);

        long long res = (halfExpo * halfExpo) % mod;

        if(exponent & 1) {
            res = (res * base) % mod;
        }

        return res;
    }
    bool patternMatch(int start, string& text, string& pat) {
        for(int i = 0; i < pat.size(); i++) {
            if(text[i + start] != pat[i]) return false;
        }
        return true;
    }
    bool RabinKarpStringMatch(string& text, string& pat) {
        int m = text.size(), n = pat.size();
        if(m < n) return false;

        int mod = 1e9 + 7;
        int d = 26; // base 26 based digit addition
        
        long long h = modularExponentiation(d, n - 1, mod);
        long long phash = 0;
        long long thash = 0;

        int i = 0;
        while(i < n) {
            phash = ((phash * d) + pat[i]) % mod;
            thash = ((thash * d) + text[i]) % mod;
            i++;
        }

        if(thash == phash && patternMatch(0, text, pat))  return true;

        while(i < m) {
            int windowStart = i - n;

            thash = (thash - (h * text[windowStart]) + mod) % mod;
            thash = ((thash * d) + text[i]) % mod;

            if(thash == phash && patternMatch(windowStart + 1, text, pat))  return true;

            i++;
        }

        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int n = b.size() / a.size();

        string na = "";
        for(int i = 0; i < n; i++) {
            na.append(a);
        }

        if(RabinKarpStringMatch(na, b)) {
            return n + 1;
        }

        na.append(a);
        if(RabinKarpStringMatch(na, b)) {
            return n + 2;
        }

        na.append(a);
        if(RabinKarpStringMatch(na, b)) {
            return n + 3;
        }

        return -1;
    }
};