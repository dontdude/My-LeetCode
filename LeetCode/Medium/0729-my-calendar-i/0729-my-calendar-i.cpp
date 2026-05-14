class MyCalendar {
    map<int, int> calendar;
public:
    MyCalendar() {
        calendar.clear();
    }
    
    bool book(int startTime, int endTime) {
        auto equalOrGreaterIt = calendar.lower_bound(startTime);

        if(equalOrGreaterIt != calendar.end() && equalOrGreaterIt->first < endTime) {
            return false;
        }

        if(equalOrGreaterIt != calendar.begin()) {
            auto prevIt = prev(equalOrGreaterIt);
            if(prevIt->second > startTime) {
                return false;
            }
        }

        calendar[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */