class Solution {
    string getFreqKey(string& str) {
        string freq(26, '0');

        for(char c : str) freq[c - 'a']++;

        return freq;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hashmap;
        vector<vector<string>> result;

        for(string str : strs) {
            string freqKey = getFreqKey(str);

            if(hashmap.find(freqKey) == hashmap.end()) {
                hashmap[freqKey] = result.size();
                result.push_back({str});
            } else {
                int indexItBelongTo = hashmap[freqKey];
                result[indexItBelongTo].push_back(str);
            }
        }

        return result;
    }
};