class Solution {
public:
    bool isSufficientSpeed(vector<int>& piles, int h, int curk){
        long long reqh = 0;
        for(auto pile : piles) {
            reqh += pile / curk;
            if(pile % curk)  reqh++;
        }
        return h >= reqh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end()), l = 1, res = r;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(isSufficientSpeed(piles, h, m))    res = m,   r = m - 1;
            else l = m + 1;
        }
        return res;
    }
};