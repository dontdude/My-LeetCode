class MyCalendarTwo {
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(const auto& overlap : overlaps) {
            if(startTime < overlap.second && endTime > overlap.first) {
                return false;
            }
        }

        for(const auto& booking : bookings) {
            if(startTime < booking.second && endTime > booking.first) {
                overlaps.push_back({max(startTime, booking.first), min(endTime, booking.second)});
            }
        }

        bookings.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */