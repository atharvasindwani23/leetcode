class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<string, vector<string>> anagrams;
        for (string str : strs) {
            string word = str;
            sort(word.begin(), word.end());
            anagrams[word].push_back(str);
        }
        vector<vector<string>> returner;
        for (auto x = anagrams.begin(); x != anagrams.end(); x++) {
            returner.push_back(x->second);
        }
        return returner;
    }
};
