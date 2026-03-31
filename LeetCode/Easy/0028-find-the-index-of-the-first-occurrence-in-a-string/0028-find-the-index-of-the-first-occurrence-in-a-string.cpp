class Solution {
    void constructLPS(int& n, string& pat, vector<int>& lps) {
        lps[0] = 0;
        int i = 1, prevLPS = 0;

        while(i < n) {
            if(pat[i] == pat[prevLPS]) {
                lps[i++] = ++prevLPS;
            } else {
                if(prevLPS == 0) {
                    lps[i++] = 0;
                } else {
                    prevLPS = lps[prevLPS - 1];
                }
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();

        vector<int> lps(n);
        constructLPS(n, needle, lps);

        int i = 0, j = 0;

        while(i < m) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;

                if(j == n) return i - n;
            } else {
                if(j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }

        return -1;
    }
};