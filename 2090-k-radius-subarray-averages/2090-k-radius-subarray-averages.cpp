class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ps(n);
        for(int i = 0; i < n; i++){
            ps[i] = nums[i];
            if(i)  ps[i] += ps[i-1];
        }

        vector<int> avg;
        for(int i = 0; i < n; i++){
            if(i < k || i + k >= n) {
                avg.push_back(-1);
                continue;
            }

            long long sum = ps[i + k] - (i-k - 1 < 0 ? 0 : ps[i-k - 1]);
            avg.push_back(sum / (2*k + 1));
        }

        return avg;
    }
};