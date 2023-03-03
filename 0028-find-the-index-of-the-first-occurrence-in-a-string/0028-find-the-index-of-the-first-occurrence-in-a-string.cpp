class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(!n)  return 0;

        vector<int> lps(n, 0);  
        calculateLps(lps, needle);
    
        int i = 0, j = 0;
        while(i < m) { 
            if (haystack[i] == needle[j]) { 
                i++, j++;
                if(j == n)   return i - n;
            } else {
                if(j)  j = lps[j - 1];   // try match with longest prefix suffix
                else i++;                // don't match -> go to next character
            }
        }
        
        return -1;
    }

    void calculateLps(vector<int>& lps, string needle){
        int i = 1, j = 0;
        while(i < needle.size()){ 
            if(needle[j] == needle[i]){
                lps[i++] = ++j;           // ++j
            } else {
                if(j)  j = lps[j - 1];    // try match with longest prefix suffix
                else i++;                 // don't match -> go to next character
            }
        }
    }
};