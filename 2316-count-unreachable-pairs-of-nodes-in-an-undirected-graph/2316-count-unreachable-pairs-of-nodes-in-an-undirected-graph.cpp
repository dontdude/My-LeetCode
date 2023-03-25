class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> dsu(n);
        iota(dsu.begin(), dsu.end(), 0);
        
        for(auto edge : edges){
            Union(edge[0], edge[1], dsu);
        }

        unordered_map<int, int> mp;
        for(auto d : dsu)   mp[Find(d,dsu)]++;

        // finding ways to select pair, inwhich first component come from one of the island and second one from any other
        long long res = 0, sum = 0;
        for(auto m : mp)  sum += m.second;
        for(auto m : mp) {
           res += (long long)m.second * (sum - m.second);
           sum -= m.second;
        } 

        return res;
    }
    void Union(int a, int b, vector<int>& dsu){
        int leadera = Find(a, dsu);
        int leaderb = Find(b, dsu);
        dsu[leaderb] = dsu[a] = dsu[b] = leadera; 
    }
    int Find(int i, vector<int>& dsu){
        if(i == dsu[i])  return i;
        return Find(dsu[i], dsu);
    }
};