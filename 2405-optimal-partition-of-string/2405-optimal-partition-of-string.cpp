class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int res = 1;
        for(auto c : s){
            if(st.find(c) != st.end()){
                st.clear();
                res++;
            }
            st.insert(c);
        }
        return res;
    }
};