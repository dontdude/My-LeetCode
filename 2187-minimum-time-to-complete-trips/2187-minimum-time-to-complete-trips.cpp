class Solution {
public:
    bool isValidTime(vector<int>& time, int totalTrips, long long tripTime){
        long long curTrips = 0;
        for(auto t : time){
            curTrips += tripTime / t;
        }
        return curTrips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long right = (long long)totalTrips * (*max_element(time.begin(), time.end()));
        long long left = 1, res = right;
        while(left <= right){ 
            long long mid = left + (right - left) / 2;
            if(isValidTime(time, totalTrips, mid)) {
                res = mid;
                right = mid - 1;
            } 
            else left = mid + 1;
        }
        return res;
    }
};