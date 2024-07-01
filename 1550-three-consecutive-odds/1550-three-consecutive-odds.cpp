class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        while(arr.size() > 2 && i < arr.size() - 2) {
           if((arr[i] & 1) == 0) {
                i += 1;
                continue;
            } else if((arr[i + 1] & 1) == 0) {
                i += 2;
                continue;
            } else if((arr[i + 2] & 1) == 0) {
                i += 3;
                continue;
            }

            return true;
        }

        return false;
    }
};