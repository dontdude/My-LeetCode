class AuthenticationManager {
    int ttl;
    unordered_map<string, int> tokenHash;
    map<int, unordered_set<string>> timeMap;

    void removeExpiredTokens(int currentTime) {
        while(timeMap.size()) {
            int minExpiryTime = timeMap.begin()->first;
            if(minExpiryTime > currentTime)  return;

            for(const string& token : timeMap[minExpiryTime]) {
                tokenHash.erase(token);
            }
            timeMap.erase(minExpiryTime);
        } 
    }
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        int expiryTime = currentTime + ttl;
        tokenHash[tokenId] = expiryTime;
        timeMap[expiryTime].insert(tokenId);
    }
    
    void renew(string tokenId, int currentTime) {
        removeExpiredTokens(currentTime);

        if(tokenHash.find(tokenId) == tokenHash.end())  return;

        int oldExpiryTime = tokenHash[tokenId];
        timeMap[oldExpiryTime].erase(tokenId);
        if(timeMap[oldExpiryTime].size() == 0) timeMap.erase(oldExpiryTime);

        generate(tokenId, currentTime);
    }
    
    int countUnexpiredTokens(int currentTime) {
        removeExpiredTokens(currentTime);

        return tokenHash.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */