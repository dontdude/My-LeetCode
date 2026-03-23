class Solution {
    bool KMPSearch(string& text, string& pat) {
        int m = text.size(), n = pat.size();
        int i = 0, j = 0;

        vector<int> lps(n, 0);
        constructLPS(lps, pat);

        while(i < m) {
            if(text[i] == pat[j]) {
                i++;
                j++;

                if(j == n)  return true;
            } else if(j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
        }

        return false;
    }

    void constructLPS(vector<int>& lps, string& pat) {
        int prevLPS = 0;
        int i = 1;
        lps[0] = 0;

        while(i < lps.size()) {
            if(pat[i] == pat[prevLPS]) {
                lps[i] == prevLPS + 1;

                i++;
                prevLPS++;
            } else if(prevLPS == 0) {
                lps[i] = 0;
                i++;
            } else {
                prevLPS = lps[prevLPS - 1];
            }
        }
    }
public:
    int repeatedStringMatch(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();

        int n = len_b / len_a;

        string na = a;
        for(int i = 1; i < n; i++) {
            na += a;
        }

        if(KMPSearch(na, b)) {
            return n;
        }

        na += a;
        if(KMPSearch(na, b)) {
            return n + 1;
        }

        na += a;
        if(KMPSearch(na, b)) {
            return n + 2;
        }

        return -1;
    }
};