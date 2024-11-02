class Solution {
public:
    int binarySearch(vector<int>& sortedList, int newEle) {
        int l = 0, r = sortedList.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(sortedList[m] >= newEle) {
                r = m - 1;
            }
            else {
               l = m + 1;
            }
        }

        return l;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> curSortedList, counts(n, 0);

        for(int i = n - 1;  i >= 0; i--) {
           int j = binarySearch(curSortedList, nums[i]); // j: pos of the number in the sorted array, created by traversing form end
           
           curSortedList.insert(curSortedList.begin() + j, nums[i]); // inserting this new number into the sorted array.
           counts[i] = j;
        }

        return counts;
    }
};