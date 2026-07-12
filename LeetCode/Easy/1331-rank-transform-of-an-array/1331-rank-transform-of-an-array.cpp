class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> hashMap;

        for(int i = 0; i < n; i++) {
            hashMap[arr[i]].push_back(i);
        }

        vector<int> result(n);
        int rank = 1;

        for(const auto& ele : hashMap) {
            for(const int& index: ele.second) {
                result[index] = rank;
            }
            rank++;
        }

        return result;
    }
};