class Solution {
    int mod = 1e9 + 7;
    long long exponent(int base, int pow) {
        if(pow == 0) return 1;
        if(pow == 1) return base;

        long long sub = exponent(base, pow / 2);

        long long res = (sub * sub) % mod;

        return (pow & 1) ? (res * base) % mod : res; 
    }

    bool isPatFound(int start, string& pat, string& txt) {
        for(int i = 0; i < pat.size(); i++) {
            if(txt[i + start] != pat[i])  return false;
        }

        return true;
    }

    bool rabinKarp(string& pat, string& txt) {
        int n = pat.size(), m = txt.size();
        if(n > m)  return false;

        int d = 26;
        long long h = exponent(d, n - 1);
        long long phash = 0, thash = 0;

        int i = 0;
        while(i < n) {
            phash = ((phash * d) % mod + pat[i] - 'a') % mod;
            thash = ((thash * d) % mod + txt[i] - 'a') % mod;
            i++;
        }

        if(phash == thash && isPatFound(0, pat, txt)) {
            return true;
        }

        while(i < m) {
            int windowStart = i - n;

            thash = (thash - ((txt[windowStart] - 'a') * h) % mod + mod) % mod;
            thash = ((thash * d) % mod + txt[i] - 'a') % mod;

            if(phash == thash && isPatFound(windowStart + 1, pat, txt)) {
                return true;
            }
            i++;
        }

        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for(string& pat : patterns) {
            if(rabinKarp(pat, word))  res++;
        }
        return res;
    }
};