class Solution {
public:
     int mergeWithReversePairCount(vector<int>& nums, int b, int m, int e) {
        int count = 0;
        for(int i = b, j = m + 1; i <= m; i++) {
           while(j <= e && nums[i] > 2LL * nums[j]) {
            j++;
           }
           count += j - (m + 1);
        }

        int i = b, j = m + 1;
        vector<int> temp;
        while(i <= m && j <= e) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while(i <= m) {
            temp.push_back(nums[i++]);
        }
        while(j <= e) {
            temp.push_back(nums[j++]);
        }

        for(int k = 0; k < temp.size(); k++) {
            nums[k + b] = temp[k];
        }

        return count;
    }
    
    int mergeSort(vector<int>& nums, int b, int e) {
        int m = b + (e - b) / 2, res = 0;
        if(b >= e)  return res;

        res += mergeSort(nums, b, m);
        res += mergeSort(nums, m + 1, e);
        res += mergeWithReversePairCount(nums, b, m, e);
        return res;
    }

    int reversePairs(vector<int>& nums) {
       return mergeSort(nums, 0, nums.size() - 1);
    }
};