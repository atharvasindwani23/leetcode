class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> expiry;
    queue<pair<int, string>> q;

    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void clean(int currentTime) {
        while (!q.empty() && q.front().first <= currentTime) {
            int expTime = q.front().first;
            string tokenId = q.front().second;
            q.pop();

            if (expiry.count(tokenId) && expiry[tokenId] == expTime) {
                expiry.erase(tokenId);
            }
        }
    }

    void generate(string tokenId, int currentTime) {
        clean(currentTime);
        int expTime = currentTime + ttl;
        expiry[tokenId] = expTime;
        q.push({expTime, tokenId});
    }

    void renew(string tokenId, int currentTime) {
        clean(currentTime);

        if (!expiry.count(tokenId)) {
            return;
        }

        int newExpTime = currentTime + ttl;
        expiry[tokenId] = newExpTime;
        q.push({newExpTime, tokenId});
    }

    int countUnexpiredTokens(int currentTime) {
        clean(currentTime);
        return expiry.size();
    }
};
