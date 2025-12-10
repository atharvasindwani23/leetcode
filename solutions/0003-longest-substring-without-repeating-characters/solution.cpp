class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxCount = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (lastSeen.count(ch) && lastSeen[ch] >= start) {
                start = lastSeen[ch] + 1;
            }
            maxCount = max(maxCount, i - start + 1);
            lastSeen[ch] = i;
        }
        return maxCount;
    }
};
