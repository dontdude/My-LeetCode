class Solution {
public:
    // Example: a = abcd
    // b = cd(abcd)ab : b = prefix + n*a + suffix  : n + 2
    // b = cd(abcd)   : b = prefix + n*a           : n + 1
    // b = (abcd)ab   : b = n*a + suffix           : n + 1
    // b = (abcd)     : b = n*a                    : n
    // where n = len(b) / len(a): how many times to repeat a
    int repeatedStringMatch(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();

        string na = "";
        int n = len_b / len_a;

        // n case
        for (int i = 0; i < n; i++)  na += a;
        if(kmpSearch(b, na)) {
            return n;
        }

        // n + 1 case
        na += a;
        if(kmpSearch(b, na)) {
            return n + 1;
        }
        

        // n + 2 case
        na += a;
        if(kmpSearch(b, na)) {
            return n + 2;
        }

        return -1;
    }

    bool kmpSearch(string pat, string txt) {
        int n = txt.size(), m = pat.size();
        int i = 0; 
        int j = 0;

        vector<int> LPS(m);
        constructLPS(pat, LPS);

        while(i < n) {
            if(txt[i] == pat[j]) {
               i++;
               j++;

               if(j == m) {
                 return true;
               }
            } else if(j == 0) {
                i++;
            } else {
                j = LPS[j - 1];
            }
        }

        return false;
    }

    void constructLPS(string pat, vector<int>& LPS) {
        int prevLPS = 0;
        int i = 1;   // starting from 1th postion
        LPS[0] = 0;

        while(i < pat.size()) {
            if(pat[i] == pat[prevLPS]) {
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