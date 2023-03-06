class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Two Concepts : 
        // 1. the number of missing under A[m] is A[m] - 1 - m.
        // 2. For this return l + k;, it can be explained in this way:
        // Now, l is the first index that gives at least k missing numbers. It may have more missing numbers than we need, so we are actually interested in index l - 1.
        // At index l - 1, we have A[l-1] - (l-1) - 1 missing numbers
        // so after index l - 1 , we need to find k - (A[l-1] - (l-1) - 1) missing numbers, i.e. k - A[l-1] + l missing numbers
        // At index l - 1, our number is A[l-1]. Add them up, the target number will be A[l-1] + k - A[l-1] + l, i.e. k + l;
        int l = 0, r = arr.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(arr[m] - 1 - m < k)  l = m + 1;
            else r = m;
        }
        return l + k;
    }
};