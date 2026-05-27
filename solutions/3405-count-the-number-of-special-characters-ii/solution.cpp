class Solution {
public:
    int numberOfSpecialChars(string word) {
        //unordered map -> ascii value, latest idx of when it was found within word
        unordered_map<int,vector<int>> freq;
        int res = 0;
        for (int i = 0; i < word.size(); i++) {
            freq[(int)word[i]].push_back(i);
        }

        for (auto x = freq.begin(); x != freq.end(); x++) {
            int ch = x->first;
            if (freq.count(ch - 32) && freq[ch][freq[ch].size() - 1] < freq[ch - 32][0]) {
                res++;
            }
        }
        return res;
    }
};
