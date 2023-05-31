class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> customer;
    unordered_map<string, pair<long long, int>> time;
    
    UndergroundSystem() {
        customer.clear();
        time.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
       
        customer[id].first = stationName;
        customer[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto incustomer = customer[id];
        string key = incustomer.first + ':' + stationName;
        long long timedif = t - incustomer.second;
        
        time[key].first += timedif;
        time[key].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        auto res = time[startStation + ':' + endStation];
        return((double)res.first/res.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */