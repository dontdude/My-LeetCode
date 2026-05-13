class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long max_milestone = 0;
        long long rest_milestones = 0;

        for(const auto& milestone : milestones) {
            max_milestone = max(max_milestone, (long long)milestone);
            rest_milestones += milestone;
        }
        rest_milestones -= max_milestone;

        if(rest_milestones + 1 < max_milestone) {
            return (rest_milestones * 2) + 1;
        } else {
            return rest_milestones + max_milestone;
        }
    }
};