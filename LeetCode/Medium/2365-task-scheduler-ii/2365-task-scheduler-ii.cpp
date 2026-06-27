class Solution {
    unordered_map<int, long long> waiting;
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long time = 0;

        for(const int& task : tasks) {
            if(waiting.find(task) != waiting.end()) {
                time = max(time, waiting[task]);
            } 

            waiting[task] = time + space + 1;
            time++;
        }

        return time;
    }
};