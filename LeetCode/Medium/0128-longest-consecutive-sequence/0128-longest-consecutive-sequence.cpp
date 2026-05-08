class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int result = 0;

        for(int num : hash) {
            if(hash.find(num - 1) != hash.end())  continue;
            int seqStartingFromCurr = 1;
            while(hash.find(num + 1) != hash.end()) {
                seqStartingFromCurr++;
                num++;
            }

            result = max(result, seqStartingFromCurr);
        }

        return result;
    }
};