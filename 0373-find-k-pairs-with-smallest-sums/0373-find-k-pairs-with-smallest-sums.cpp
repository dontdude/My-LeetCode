class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // similar to bfs
        // push the first pair, (for sure smallest), say (i, j)
        // now, next pair to consider will be (i + 1, j) and (i, j + 1)
        // since certain pair may repeat, use set

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;        // minheap for sum of pairs
        set<pair<int, int>> st;
        vector<vector<int>> res;

        st.insert({0, 0});
        pq.push({nums1[0] + nums2[0], {0, 0}});  
         
        while(k-- && !pq.empty()){
            auto curPair = pq.top();    pq.pop();
            int i = curPair.second.first, j = curPair.second.second;
            res.push_back({nums1[i], nums2[j]});

            if(i+1 < nums1.size() && st.find({i+1, j}) == st.end()){    //pair (i+1, j)
                st.insert({i+1, j});
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
            }
            if(j+1 < nums2.size() && st.find({i, j+1}) == st.end()){   // pair (i, j+1)
                st.insert({i, j+1});  
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
            }
        }

        return res;
    }
};