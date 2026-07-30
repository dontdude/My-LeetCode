class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total = 0;
        int mx = 0;

        for(const int& milestone : milestones) {
            total += milestone;
            mx = max(mx, milestone);
        }

        long long res = total - mx;
        return min(total, res * 2 + 1);  // min(all milestone doable, mx milestone is too much, can only do rest * 2 + 1)
    }
};