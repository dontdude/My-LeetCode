class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);

        int right = 0, left = 0, n = s.size();
        int maxCountInCurrWindow = 0, result = 0;

        while(right < n) {
            count[s[right] - 'A']++;
            maxCountInCurrWindow = max(maxCountInCurrWindow, count[s[right] - 'A']);
            right++;

            while((right - left) - maxCountInCurrWindow > k) {
                count[s[left] - 'A']--;
                maxCountInCurrWindow = *max_element(count.begin(), count.end());
                left++;
            }  

            result = max(result, right - left);     
        }

        return result;
    }
};