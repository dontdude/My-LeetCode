class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for(char task : tasks) {
            count[task - 'A']++;
        }

        for(int i = 0; i < 26; i++) {
            if(count[i] > 0)  pq.push(count[i]);
        }
        
        int time = 0;

        while(!pq.empty() || !q.empty()) {
            time++;

            while(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()) {
                int taskCount = pq.top();
                pq.pop();

                if(taskCount - 1 > 0) {
                    q.push({taskCount - 1, time + n + 1});
                }
            }
        }

        return time;
    }
};