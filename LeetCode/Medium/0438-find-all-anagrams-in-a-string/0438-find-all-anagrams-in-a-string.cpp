class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size(), ps = p.size();
        if(ss < ps)   return {};

        vector<int> phash(26, 0);
        for(char pc : p) {
            phash[pc - 'a']++;
        }

        int count = ps;   // Count of match to find
        int left = 0, right = 0;
        vector<int> res;

        while(right < ss) {
            if(phash[s[right] - 'a'] > 0) { 
                count--;    // added a matching char, less count of match to find
            }

            phash[s[right] - 'a']--;   // always decrement, even if nonuseful char of s, goes negative
            right++;

            if(count == 0)  res.push_back(left);

            if(right - left == ps) {
                if(phash[s[left] - 'a'] >= 0) { 
                    count++;   // removing from left a matching char
                }

                phash[s[left] - 'a']++;  // always increment, to even make nonuseful char hash as zero.
                left++;
            }
        }

        return res;
    }
};