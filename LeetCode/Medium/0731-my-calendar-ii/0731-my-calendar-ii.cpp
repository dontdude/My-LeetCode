class MyCalendarTwo {
    map<int, int> timeline;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        timeline[startTime]++;
        timeline[endTime]--;

        int overlaps = 0;
        for(const auto& points : timeline) {
            overlaps += points.second;

            if(overlaps > 2) {
                if(--timeline[startTime] == 0) timeline.erase(startTime);
                if(++timeline[endTime] == 0) timeline.erase(endTime);
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */