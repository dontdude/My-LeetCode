class Solution {
public:
    string stringFreqKey(string s) {
        vector<int> count(26, 0);

        for(int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }

        string freqKey = "";
        for(int i = 0; i < 26; i++) {
            string charStr = to_string('a' + i);
            string countStr = to_string(count[i]);
            freqKey += charStr + "#" + countStr;
        }

        return freqKey;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for(string str: strs) {
            string freqKey = stringFreqKey(str);
            anagrams[freqKey].push_back(str);
        }

        vector<vector<string>> res;

        for(auto anagram : anagrams) {
            res.push_back(anagram.second);
        }

        return res;
    }
};