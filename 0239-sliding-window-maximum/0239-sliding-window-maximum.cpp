class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i = 0; i < k; i++) {
            while(!dq.empty() && dq.front() < nums[i]) {  // monotonic stack, like:  back -> 3 2 1 <- front
                dq.pop_front();
            }

            dq.push_front(nums[i]);
        }

        res.push_back(dq.back());   // back will always have the biggest element, in the current window
        for(int i = k; i < nums.size(); i++) {
            while(!dq.empty() && dq.front() < nums[i]) { // if equal still push
                dq.pop_front();
            }

            if(!dq.empty() && dq.back() == nums[i - k]) {  // if elem to be removed is equal to back elemt.. pop it
                dq.pop_back();
            }
           
            dq.push_front(nums[i]);
            res.push_back(dq.back());  
        }

        return res;
    }
};