class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        int left = 0, right = 0, count = 0;
        vector<int> freq(58, 0);

        for(int i = 0; i < n; i++) {
            freq[t[i] - 'A']++;
            count++;
        }

        int resS = 0, resE = m + 1;

        while(right < m) {
            if(freq[s[right] - 'A']-- > 0) count--;

            right++;

            while(count == 0 && left < right) {
                if(count == 0 && (resE - resS) > (right - left)) {
                    resE = right;
                    resS = left;
                }

                if(freq[s[left] - 'A']++ >= 0)  count++;
                left++;
            }
        }

        if(resE == m + 1)  return "";
        return s.substr(resS, resE - resS);
    }
};