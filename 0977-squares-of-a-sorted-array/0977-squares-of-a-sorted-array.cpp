class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos;
        for(auto n : nums) {
            if(n < 0)  neg.push_back(n * n);
            else pos.push_back(n * n);
        }

        int i = neg.size() - 1, j = 0, k = 0;
        while(i >= 0 && j < pos.size()){
            if(neg[i] < pos[j])  nums[k++] = neg[i--];
            else  nums[k++] = pos[j++];
        }
        while(i >= 0)  nums[k++] = neg[i--];
        while(j < pos.size())  nums[k++] = pos[j++];

        return nums;
    }
};