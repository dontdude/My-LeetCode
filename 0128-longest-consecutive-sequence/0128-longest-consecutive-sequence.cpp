class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;   // first = element, second = length of sequence where it belongs

        for(auto n : nums){
            if(mp[n])  continue;     //it is in the middle of some consecutive sequence 
        
            if(mp[n+1] == 0 && mp[n-1] == 0){         // no sequence found where n belongs
                mp[n] = 1;
            }

            else if(mp[n+1] == 0) {           // current element is only last element is some sequence 
               mp[n] = mp[n-1] + 1;        // updaing the length and saving it in new last elment
               mp[n - mp[n-1]] = mp[n];    // first element of this sequence(n - mp[n-1]) also saves length update 
            }

            else if(mp[n-1] == 0) {           // current element is only first element is some sequence 
               mp[n] = mp[n+1] + 1;        // updaing the length and saving it in new first elment
               mp[n + mp[n+1]] = mp[n];    // last element of this sequence(n - mp[n-1]) also saves length update 
            }

            else {                          // current element joins two disjoint sequence
                mp[n] = 1 + mp[n+1] + mp[n-1];
                mp[n - mp[n-1]] = mp[n];
                mp[n + mp[n+1]] = mp[n];
            }

            res = max(res, mp[n]);
        }

        return res;
    }
};