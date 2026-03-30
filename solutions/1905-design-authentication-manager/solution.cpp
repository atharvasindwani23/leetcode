class AuthenticationManager {

private:

unordered_map<string, int> tokenExpiry;
queue<pair<int,string>> tokens;
int ttl = 0;

void clean(int currentTime) {
    while (!tokens.empty() && tokens.front().first <= currentTime) {
        auto [time, id] = tokens.front();
        tokens.pop();
        if (tokenExpiry.count(id) && tokenExpiry[id] == time) {
            tokenExpiry.erase(id);
        }
    }
}
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        clean(currentTime);
        if (tokenExpiry.count(tokenId)) {
            return;
        }
        tokenExpiry[tokenId] = ttl + currentTime;
        tokens.push({ttl + currentTime, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        clean(currentTime);
        if (!tokenExpiry.count(tokenId) || tokenExpiry[tokenId] <= currentTime) {
            return;
        }
        tokenExpiry[tokenId] = currentTime + ttl;
        tokens.push({ttl + currentTime, tokenId});

    }
    int countUnexpiredTokens(int currentTime) {
        clean(currentTime);
        // int count = 0;
        // for (auto x = tokenExpiry.begin(); x != tokenExpiry.end(); x++) {
        //     if (x->second > currentTime) {
        //         count++;
        //     }
        // }
        // return count;
        return tokenExpiry.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
