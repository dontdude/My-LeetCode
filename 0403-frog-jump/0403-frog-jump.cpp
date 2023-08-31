class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int, set<int>> dp;
        vector<int> delta = {-1, 0, 1};

        dp[stones[0]].insert(1);

        for(int i = 0; i < n; i++){
            if(dp.count(stones[i])) {
               set<int> jumps = dp[stones[i]];

               for(auto jump : jumps){
                   int nextStone = stones[i] + jump;
                   for(int j = 0; j < 3; j++){
                       dp[nextStone].insert(jump + delta[j]);
                   }
               }
            }
        }   

        return dp.count(stones[n-1]);                     
    }
};