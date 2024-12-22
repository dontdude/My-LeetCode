class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());

        int res = 0, child = 0, cookie = 0;
        while(cookie < s.size() && child < g.size()) {
            if(s[cookie] >= g[child]) {
               cookie++;
               child++;
               res++;
            } else {
               child++;
            }
        }

        return res;
    }
};