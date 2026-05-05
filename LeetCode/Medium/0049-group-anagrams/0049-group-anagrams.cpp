class Solution {
    string getFreqKey(string str) {
        vector<int> count(26, 0);
        for(char c : str) count[c - 'a']++;

        string freqKey = "";
        for(int i = 0; i < 26; i++) {
            string freq = to_string(count[i]);
            freq.push_back('a' + i);
            freqKey.append(freq);
        }

        return freqKey;
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