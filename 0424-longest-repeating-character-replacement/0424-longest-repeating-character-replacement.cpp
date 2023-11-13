class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int i = 0, j = 0, maxOcc = 0, res = 0;
        
        // count of unwanted char = total char - count of max occuring char
        while(i < s.size()) {
            count[s[i] - 'A']++;
            maxOcc = max(maxOcc, count[s[i] - 'A']);

            while((i-j + 1) - maxOcc > k) {
                count[s[j++] - 'A']--;

                for(int k = 0; k < 26; k++){
                    maxOcc = max(maxOcc, count[k]);
                }
            }

            res = max(res, (i-j) + 1);
            i++;
        }

        return res;
    }
};