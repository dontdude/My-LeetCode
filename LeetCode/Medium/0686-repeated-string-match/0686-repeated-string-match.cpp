class Solution {
    long long power(int base, int exponent, int modulo) {
        if(exponent == 0)  return 1;
        if(exponent == 1)  return (long long)base;

        long long halfPower = power(base, exponent / 2, modulo);
        long long result = (halfPower * halfPower) % modulo;

        if(exponent & 1) {
            result = (base * result) % modulo;
        }

        return result;
    }
    bool isPatFound(int start, string& text, string& pat) {
        int n = pat.size();

        for(int i = 0; i < n; i++) {
            if(text[i + start] != pat[i])  return false;
        }

        return true;
    }
    bool RabinKarpSearch(string& text, string& pat) {
        int m = text.size(), n = pat.size();

        if (m < n) return false;
        
        int d = 26;   // strings consist of lowercase letters only
        long long q = 1e9 + 7;   // large prime number for modulo

        long long h = power(d, n - 1, q);
        long long phash = 0;
        long long thash = 0;

        int i = 0;
        while(i < n) {
            phash = ((d * phash) + pat[i]) % q;
            thash = ((d * thash) + text[i]) % q;
            i++;
        }

        if(phash == thash && isPatFound(i - n, text, pat)) {
            return true;
        }

        while(i < m) {
            int currWindowStart = i - n;

            thash = (thash - (h * (text[currWindowStart]) % q) + q) % q;   // removing shifted window char

            thash = ((d * thash) +  text[i]) % q;  // adding new window char

            if(phash == thash && isPatFound(currWindowStart + 1, text, pat)) {
                return true;
            }

            i++;
        }

        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();

        int n = len_b / len_a;

        string na = "";
        for(int i = 0; i < n; i++) {
            na += a;
        }

        if(RabinKarpSearch(na, b)) {
            return n;
        }

        na += a;
        if(RabinKarpSearch(na, b)) {
            return n + 1;
        }

        na += a;
        if(RabinKarpSearch(na, b)) {
            return n + 2;
        }

        return -1;
    }
};