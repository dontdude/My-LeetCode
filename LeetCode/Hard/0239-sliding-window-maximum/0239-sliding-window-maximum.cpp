class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> mds;  // monotonic decreasing: want next greater everytime 

        for(int i = 0; i < k; i++) {
            while(mds.empty() == false && mds.back() < nums[i]) {
                mds.pop_back();
            }

            mds.push_back(nums[i]);
        }

        vector<int> maxFromWindows;
        maxFromWindows.push_back(mds.front());

        for(int i = k; i < nums.size(); i++) {
            while(mds.empty() == false && mds.back() < nums[i]) {  // add new window elem to mds
                mds.pop_back();
            }

            if(mds.empty() == false && mds.front() == nums[i - k]) {  // delete removed window elem from mds
                mds.pop_front();
            }

            mds.push_back(nums[i]);
            maxFromWindows.push_back(mds.front());
        }

        return maxFromWindows;
    }
};