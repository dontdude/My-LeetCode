class Solution {
public:
    int hIndex(vector<int>& citations) {
        int mxhpossible = 0;
        for(auto c : citations) {
            mxhpossible = max(mxhpossible, c);
        }

        vector<int> hs(mxhpossible + 1, 0);   // each hs[i] will tell the count of i or bigger citation value present in citations
        for(int c : citations) {
           hs[c]++;
        }

        for(int i = mxhpossible; i >= 1; i--) {
            hs[i-1] += hs[i];

            if(hs[i] >= i) {   //atleast h papers
                return i;
            }
        }

        return 0;
    }
};