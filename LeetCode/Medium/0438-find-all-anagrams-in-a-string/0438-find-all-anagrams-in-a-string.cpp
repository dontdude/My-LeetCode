class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size(), ps = p.size();
        if(ss < ps) return {};

        vector<int> p_hash(26, 0);

        for(char c : p) {
            p_hash[c - 'a']++;
        }

        vector<int> anagramIndexs;
        int count = ps;
        int left = 0, right = 0;

        while(right < ss) {
            int rightChar = s[right] - 'a';

            if(p_hash[rightChar] > 0) {
                count--;
            }

            p_hash[rightChar]--;
            right++;

            if(right - left == ps) {
                if(count == 0) {
                    anagramIndexs.push_back(left);
                }

                int leftChar = s[left] - 'a';

                if(p_hash[leftChar] >= 0) {
                    count++;
                }

                p_hash[leftChar]++;
                left++;
            }
        }

        return anagramIndexs;
    }
};