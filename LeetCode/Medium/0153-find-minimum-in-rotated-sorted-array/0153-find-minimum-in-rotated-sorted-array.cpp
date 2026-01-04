class Solution {
public:
    int findMin(vector<int>& a) {
        
        int l = 0, r = a.size() - 1;
        
        while(l <= r){
            int m = l + (r-l)/2;

            if(m && a[m] < a[m-1])    return a[m];
            
            else if((a[l] <= a[r] || a[l] > a[m]))  r = m - 1;
            else  l = m + 1;
        }

        return a[0];
    }
};