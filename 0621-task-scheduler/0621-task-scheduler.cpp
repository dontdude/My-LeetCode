class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // for the case, when no of unique elements > n+1, in that case output is task.size(), 
        // therefore no need to create those groups of task individually,
        // just use the count max occ logic, you used in previous solution

        unordered_map<char, int> mp;
        int mx = 0;

        for(int i = 0; i < tasks.size(); i++){
            mp[tasks[i]]++;
            mx = max(mx, mp[tasks[i]]);
        }

        int times = 0;
        for(auto m : mp)  if(m.second == mx)  times++;
        
        int res = (mx - 1) * (n + 1) + times;

        return max(res, (int)tasks.size());
    }
};