class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = 0;
        int ws = 0, wr = n, wdiffSum = 0, minWdiffSum = INT_MAX;

        while(right < n) {
            wdiffSum += abs(arr[right] - x);
            right++;

            if(right - left == k) {
                if(minWdiffSum > wdiffSum) {
                    ws = left;
                    wr = right;
                    minWdiffSum = wdiffSum;
                }

                wdiffSum -= abs(arr[left] - x);
                left++;
            }
        }

        vector<int> result(arr.begin() + ws, arr.begin() + wr);
        return result;
    }
};