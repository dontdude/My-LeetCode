class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        vector<int> LPS(m, 0);
        constructLPS(needle, LPS);

        int i = 0, j = 0;
        while(i < n) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;

                if(j == m) {
                    return i - j;
                }
            } else if (j == 0) {
                i++;
            } else {
                j = LPS[j - 1];
            }
        }

        return -1;
    }

    void constructLPS(string needle, vector<int>& LPS) {
        int i = 1;
        int prevLPS = 0;
        LPS[0] = 0;

        while(i < needle.size()) {
            if(needle[i] == needle[prevLPS]) {
                prevLPS++;
                LPS[i] = prevLPS;
                i++;
            } else if (prevLPS == 0) {
                LPS[i] = 0;
                i++;
            } else {
                prevLPS = LPS[prevLPS - 1];
            }
        }
    }
};