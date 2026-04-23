class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxOcc = 0, result = 0;
        vector<int> count(26, 0);

        while(right < s.size()) {
            count[s[right] - 'A']++;
            maxOcc = max(maxOcc, count[s[right] - 'A']);
            right++;

            while((right - left) - maxOcc > k) {
                count[s[left] - 'A']--;
                left++;
            } 

            result = max(result, right - left);
        }

        return result;
    }
};