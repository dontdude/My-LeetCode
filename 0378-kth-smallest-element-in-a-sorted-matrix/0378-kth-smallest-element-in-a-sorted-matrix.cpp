class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i < matrix.size(); i++)  pq.push({matrix[i][0], {i, 0}});
        
        int res = 0; 
        while(k--){
            auto curr = pq.top();   pq.pop();
            res = curr.first;
            int i = curr.second.first, j = curr.second.second;

            if(j + 1 < matrix[i].size()) {
                pq.push({matrix[i][j+1], {i, j+1}});
            }
        }

        return res;
    }
};