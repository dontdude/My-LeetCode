class Solution {
    struct SumPairs {
        int sum;
        int u;
        int v;

        SumPairs(int s, int i, int j) {
            sum = s;
            u = i;
            v = j;
        }
    };

    struct comparator {
        bool operator()(SumPairs a, SumPairs b) {
            return a.sum > b.sum;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();

        priority_queue<SumPairs, vector<SumPairs>, comparator> pq;

        vector<vector<int>> res;

        for(int i = 0; i < m && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(res.size() < k && pq.empty() == false) {
            int u = pq.top().u;
            int v = pq.top().v;
            pq.pop();
            
            res.push_back({nums1[u], nums2[v]});

            if(v + 1 < n) {
                pq.push({nums1[u] + nums2[v + 1], u, v + 1});
            }
        }

        return res;
    }
};