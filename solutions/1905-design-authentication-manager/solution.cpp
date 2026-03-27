class AuthenticationManager {
public:

    int tokenTime = 0;
    unordered_map<string, int> tokenLife; //maps token to when itll expire
    AuthenticationManager(int timeToLive) {
        tokenTime = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokenLife[tokenId] = currentTime + tokenTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokenLife[tokenId] <= currentTime) {
            return;
        }   
        tokenLife[tokenId] = currentTime + tokenTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto x = tokenLife.begin(); x != tokenLife.end(); x++) {
            if (x->second > currentTime) {
                count++;
            }
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
