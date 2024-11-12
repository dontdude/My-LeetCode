class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXors(n, 0), answer;
        for(int i = 0; i < n; i++) {
           prefixXors[i] = (i == 0) ? arr[0] : (arr[i] ^ prefixXors[i - 1]);
        }

        for(auto query : queries) {
            int leftPartitionXor = query[0] > 0 ? prefixXors[query[0]- 1] : 0;
            answer.push_back(prefixXors[query[1]] ^ leftPartitionXor);
        }

        return answer;
    }
};