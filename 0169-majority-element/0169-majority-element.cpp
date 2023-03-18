class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], vote = 1, n = nums.size();
        for(int i = 1; i < n; i++){
            if(candidate == nums[i])  vote++;
            else vote--;
           
            if(vote == 0){
                candidate = nums[i];
                vote = 1;
            }
        }

        return candidate;
    }
};