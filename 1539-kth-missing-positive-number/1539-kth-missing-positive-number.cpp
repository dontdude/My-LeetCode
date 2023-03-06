class Solution {
public:
    int binarySearch(vector<int>& arr, int x){
        int l = 0, r = arr.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(arr[m] == x)  return m;
            else if(arr[m] < x)  l = m + 1;
            else r = m - 1;
        }
        return -1;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        while(k != 0){
            if(binarySearch(arr, i) == -1)   k--;
            i++;
        }
        return i-1;
    }
};