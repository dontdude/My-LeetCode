class Solution {
    int mod = 1e9 + 7;
    long long exponent(int base, int pow) {
        if(pow == 0) return 1;
        if(pow == 1) return base;

        long long sub = exponent(base, pow / 2);
        long long res = (sub * sub) % mod;

        return (pow & 1) ? (res * base) % mod : res;
    }

    bool isEqual(int start, string& pat, string& txt) {
        for(int i = 0; i < pat.size(); i++) {
            if(txt[start + i] != pat[i]) return false;
        }
        return true;
    }
    bool RabinKarp(string& pat, string& txt) {
        int d = 26;
        int n = pat.size(), m = txt.size();
        if(m < n) return false;

        long long patHash = 0, txtHash = 0;
        long long h = exponent(d, n - 1);
        int i = 0;

        for(; i < n; i++) {
            patHash = ((patHash * d) + pat[i] - 'a') % mod;
            txtHash = ((txtHash * d) + txt[i] - 'a') % mod;
        }

        if(patHash == txtHash && isEqual(0, pat, txt)) {
            return true;
        }

        for(; i < m; i++) { 
            txtHash = (txtHash - (((txt[i - n] - 'a') * h) % mod) + mod) % mod;
            txtHash = ((txtHash * d) + txt[i] - 'a') % mod;

            if(patHash == txtHash && isEqual(i - n + 1, pat, txt)) {
                return true;
            }
        }

        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int n = b.size() / a.size();

        string na = "";
        for(int i = 0; i < n; i++)  na.append(a);

        if(RabinKarp(b, na))  return n;

        na.append(a);
        if(RabinKarp(b, na))  return n + 1;
        
        na.append(a);
        if(RabinKarp(b, na))  return n + 2;

        return -1;
    }
};