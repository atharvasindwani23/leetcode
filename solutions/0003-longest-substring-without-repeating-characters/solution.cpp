class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int maxLen = 0;
        unordered_map<char, int> lastSeen;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (lastSeen.count(ch) && lastSeen[ch] >= start) {
                start = lastSeen[ch] + 1;
            }
            lastSeen[ch] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;      
    }
};
