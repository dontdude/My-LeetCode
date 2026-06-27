class MyCalendar {
    map<int, int> timeline;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it = timeline.lower_bound(startTime);

        if(it != timeline.end()) {
            if(endTime > it->first) {
                return false;
            }
        }
        
        if(it != timeline.begin()) {
            auto prevIt = prev(it);
            if(startTime < prevIt->second) {
                return false;
            }
        }
        
        timeline[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */