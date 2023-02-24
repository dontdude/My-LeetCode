class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        for(auto n : nums){
            if(n&1)  st.insert(n*2);           // making every number even, so that later on only one operation (divide by 2) is required
            else st.insert(n);
        }

        int res = *st.rbegin() - *st.begin();

        while(!(*st.rbegin() & 1)) {                 // while max element is even
            int mxeven = *st.rbegin();   
            st.erase(mxeven);
            st.insert(mxeven / 2);

            res = min(res, *st.rbegin() - *st.begin());
        }

        return res;
    }
};