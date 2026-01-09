class Solution {
public:
   vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lastDiff = INT_MAX;
        int low = 0, high = n - k;   

        while(low < high) {
            int mid = low + (high - low) / 2;

            int currentDiff = x - arr[mid];
            int nextWindowDiff = arr[mid + k] - x;

            if(currentDiff > nextWindowDiff) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};