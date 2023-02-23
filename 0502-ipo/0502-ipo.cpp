class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int i = 0, n = capital.size();
        vector<pair<int, int>> projects;
        for(i = 0; i < n; i++)  projects.push_back({capital[i], profits[i]});
        sort(projects.begin(), projects.end());

        i = 0;
        priority_queue<int> pq;
        while(k--){
           while(i < n && projects[i].first <= w)    pq.push(projects[i++].second);
           
           if(pq.empty())  break;
           w += pq.top();    pq.pop();
        }

        return w;
    }
};