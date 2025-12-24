class Solution {
public:
    string minWindow(string s, string t) {
        int ts = t.size(), ss = s.size();
        if(ss < ts)  return "";

        vector<int> t_hash(128, 0);
        for(char c : t)  t_hash[c]++;

        int left = 0, right = 0;
        int resLeft = 0, resRight = INT_MAX;
        int count = ts;

        while(right < ss) {  
            if(t_hash[s[right]] > 0) {
                count--;
            }

            t_hash[s[right]]--;
            right++;

            while(count <= 0) {
                if(right - left < resRight - resLeft) {
                    resRight = right;
                    resLeft = left;
                }

                if(t_hash[s[left]] >= 0) {
                    count++;
                }

                t_hash[s[left]]++;
                left++;
            }
        }

        if(resRight == INT_MAX)  return ""; 

        return s.substr(resLeft, resRight - resLeft);
    }
};