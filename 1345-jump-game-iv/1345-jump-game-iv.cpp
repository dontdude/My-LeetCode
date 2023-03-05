class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> nextIndices;
        for(int i = 0; i < n; i++)  nextIndices[arr[i]].push_back(i);

        int level = -1;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);   vis[0] = true;
      
        while(!q.empty()){
            int s = q.size();
            level++;

            while(s--){
              int u = q.front();   q.pop();
              if(u == n - 1)  return level;

              nextIndices[arr[u]].push_back(u + 1);
              if(u)  nextIndices[arr[u]].push_back(u - 1);
              for(auto v : nextIndices[arr[u]]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
              }
              nextIndices[arr[u]].clear();
              //If we do not clear nextIndices at the end of each iteration of the while loop, it will keep storing the indices for the same value and also the indices to which we can jump from the previous iterations as well, leading to incorrect results or time limit exceeded. ( Giving TLE )
            }
        }
        return -1;
    }
};