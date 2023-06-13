class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(int i = 0; i < tasks.size(); i++)  mp[tasks[i]]++;

        priority_queue<pair<int, char>> pq;
        for(auto m : mp)  pq.push({m.second, m.first});

        int res = 0;
        while(pq.size() >= n+1){
            vector<pair<int, char>> temp(n+1);
            for(int i = 0; i < n+1; i++){
                auto curr = pq.top();   pq.pop();
                temp[i] = {curr.first - 1, curr.second};
            }
            for(int i = 0; i < n+1; i++){
                if(temp[i].first)  pq.push(temp[i]);
            }
            res += n+1;
        }
        
        int mx = -1, times = 0;
        while(!pq.empty() && (mx == -1 ||  mx == pq.top().first)){ 
            mx = pq.top().first;  pq.pop();  
            times++;
        }
        if(times)  res += (mx - 1) * (n + 1) + times;

        return res;
    }
};