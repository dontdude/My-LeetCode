class Solution {
public:
    bool isAnagram(vector<int> shash, vector<int> phash) {
        return shash == phash;
    }

    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())  return vector<int>();

        vector<int> phash(26, 0), shash(26, 0);
        vector<int> res;

        for(char c : p) {
            phash[c - 'a']++;
        }

        for(int i = 0; i < p.size(); i++) {
            shash[s[i] - 'a']++;
        } 

        if(isAnagram(phash, shash)) {
            res.push_back(0);
        }

        for(int i = p.size(); i < s.size(); i++) {
            int remove = i - p.size();
            shash[s[remove] - 'a']--;
            shash[s[i] - 'a']++;

            if(isAnagram(phash, shash)) {
                res.push_back(remove + 1);
            }
        }

        return res;
    }
};