class SeatManager {
    set<int> availableOrderedSeats;
public:
    SeatManager(int n) {
        for(int i = 1; i <= n; i++)  availableOrderedSeats.insert(i);
    }
    
    int reserve() {
        int firstAvailableSeat = *availableOrderedSeats.begin();
        availableOrderedSeats.erase(firstAvailableSeat);
        return firstAvailableSeat;
    }
    
    void unreserve(int seatNumber) {
        availableOrderedSeats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */