class BrowserHistory {
public:
    int cap;
    int ind;
    vector<string> history;

    BrowserHistory(string homepage) {
        cap = 1;
        ind = 0;
        history.push_back(homepage);
    }
    
    void visit(string url) {
        ind++; 

        if(ind == cap)    history.push_back(url);
        else {
            history[ind] = url;
            history.resize(ind + 1);
        }
 
        cap = ind + 1;
    }
    
    string back(int steps) {
        ind = ind > steps ? ind - steps : 0;
        return history[ind];
    }
    
    string forward(int steps) {
        ind = ind + steps < cap ? ind + steps : cap - 1;
        return history[ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */