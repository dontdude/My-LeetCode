class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size(), res = 0, ind = 0, psum = 0;
        for(int i = 0; i < n; i++) {
            if(satisfaction[i] >= 0){
                ind = i;               // ind = index of first non negative number
                while(i < n) {
                    res += (i - ind + 1) * satisfaction[i];
                    psum += satisfaction[i];               
                    // if we include 1 extra number(maybe from negative), than our result will have psum increase, 
                    // This is because every positive number will get 1 occurance more, so total positive change in one inclusion = psum
                    i++; 
                }
            }
        }

        if(ind){        // if ind is not our first position
            int nsum = abs(satisfaction[--ind]);
            while(ind > 0 && nsum < psum){
               res += psum - nsum;
               // if we are including a new negative number, than new change will be =  positive sum from shifting of positive digits - sum from negative digits shifts
               nsum = nsum + abs(satisfaction[--ind]);   // Adding new negative number to the neg sum, and also including sum increse due to shift(which will be prev neg sum value)
            }
            if(psum > nsum)  res += psum - nsum;   
        }

        return res;
    }
};