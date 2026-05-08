class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int left = 0, right = 0;
        int result = 0;

        while(right < s.size()) {
            char c = s[right];
            hashmap[c]++;
            right++;

            while(hashmap[c] > 1) {
                hashmap[s[left]]--;
                left++;
            }

            result = max(result, right - left);
        }

        return result;
    }
};