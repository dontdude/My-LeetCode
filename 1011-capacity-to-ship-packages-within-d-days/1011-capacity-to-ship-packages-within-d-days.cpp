class Solution {
public:
    bool isPossibleResult(vector<int>& weights, int days, int res){
        int cap = res, reqdays = 1;
        for(auto w : weights){
            if(cap < w) {
                cap = res;
                reqdays++;
            }
            cap -= w;
        }

        return (days >= reqdays);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int mw = 0, n = weights.size();
        for(auto w : weights)  mw = max(mw, w);

        int left = mw, right = mw * n, res = right;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isPossibleResult(weights, days, mid)){
                res = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return res;
    }
};