class Solution {
    long long power(int base, int pow, int mod) {
        if(pow == 0)  return 1;
        if(pow == 1)  return base;

        long long halfPower = power(base, (pow >> 1), mod);

        long long curr = (halfPower * halfPower) % mod;

        return (pow & 1) ? ((curr * base) % mod) : curr;
    }
    bool patFound(int start, string& txt, string& pat) {
        for(int j = 0; j < pat.size(); j++) {
            if(pat[j] != txt[j + start]) return false;
        }
        return true;
    }
    int RabinKarp(int m, int n, string& txt, string& pat) {
        if(m < n)  return -1;

        int d = 26; // lowercase only
        long long mod = 1e9 + 7;

        long long h = power(d, n - 1, mod);

        long long phash = 0;
        long long thash = 0;

        for(int j = 0; j < n; j++) {
            phash = ((phash * d) + (pat[j] - 'a')) % mod;
            thash = ((thash * d) + (txt[j] - 'a')) % mod;
        }

        if(phash == thash && patFound(0, txt, pat)) {
            return 0;
        }

        for(int i = n; i < m; i++) {
            thash = (thash - (h * (txt[i - n] - 'a')) % mod + mod) % mod;
            thash = ((thash * d) + (txt[i] - 'a')) % mod;
            if(phash == thash && patFound(i - n + 1, txt, pat)) {
                return i - n + 1;
            }
        }

        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();

        return RabinKarp(m, n, haystack, needle);
    }
};