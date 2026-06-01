class RandomizedCollection {
    int n;
    vector<int> collection;
    unordered_map<int, unordered_set<int>> index;
public:
    RandomizedCollection() {
        n = 0;
    }
    
    bool insert(int val) {
        bool noPresent = index.find(val) == index.end();

        collection.push_back(val);
        index[val].insert(n);
        n++;

        return noPresent;
    }
    
    bool remove(int val) {
        if(index.find(val) == index.end()) return false;

        int emptyIndex = *index[val].begin();
        int lastVal = collection.back();

        index[val].erase(emptyIndex);
        index[lastVal].insert(emptyIndex);
        index[lastVal].erase(n - 1);

        if(index[val].empty())  index.erase(val);

        collection[emptyIndex] = lastVal;
        collection.pop_back(); 
        n--;

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % n;
        return collection[randomIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */