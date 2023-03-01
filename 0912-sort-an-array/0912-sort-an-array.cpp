class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r){
        vector<int> leftArr, rightArr;
        for(int i = l; i <= m; i++)  leftArr.push_back(nums[i]);
        for(int i = m + 1; i <= r; i++)  rightArr.push_back(nums[i]);

        int i = 0, j = 0, k = l, ls = leftArr.size(), rs = rightArr.size();
        while(i < ls && j < rs){
            if(leftArr[i] < rightArr[j])  nums[k++] = leftArr[i++];
            else nums[k++] = rightArr[j++];
        }
        while(i < ls)  nums[k++] = leftArr[i++];
        while(j < rs)  nums[k++] = rightArr[j++];
    }

    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right)  return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};