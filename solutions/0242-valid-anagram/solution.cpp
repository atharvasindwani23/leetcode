class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::map<char, int> freq;
        std::map<char, int> freq_2;
        for (unsigned int i  = 0; i < s.size(); i++) {
            if (freq.contains(s[i])) {
                freq[s[i]]++;
            } else {
                freq[s[i]] = 1;
            }
        }
        for (unsigned int i  = 0; i < t.size(); i++) {
            if (freq_2.contains(t[i])) {
                freq_2[t[i]]++;
            } else {
                freq_2[t[i]] = 1;
            }
        }
        for (unsigned int i = 0; i < t.size(); i++) {
             if (freq.contains(t[i]) == false || freq[t[i]] != freq_2[t[i]]) {
                return false;
             }
        }
        return true;
    }
};
