class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hashmap;
        vector<vector<string>> result;

        for(string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            if(hashmap.find(sortedStr) == hashmap.end()) {
                hashmap[sortedStr] = result.size();
                result.push_back({str});
            } else {
                int indexItBelongTo = hashmap[sortedStr];
                result[indexItBelongTo].push_back(str);
            }
        }

        return result;
    }
};