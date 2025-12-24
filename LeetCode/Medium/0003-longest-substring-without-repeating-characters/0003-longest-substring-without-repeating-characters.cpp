class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1)  return n;

        unordered_map<char, int> alphabetMap;

        int windowStart = 0;
        int longestSub = 1;

        for(int i = 0; i < n; i++) {
            int lastOccr = -1;
            if(alphabetMap.find(s[i]) != alphabetMap.end()) {
                lastOccr = alphabetMap[s[i]];
            };

            if(windowStart <= lastOccr) {
                windowStart = lastOccr + 1;
            } 
            
            longestSub = max(longestSub, i - windowStart + 1);
            alphabetMap[s[i]] = i; 
        }

        return longestSub;
    }
};