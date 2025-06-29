class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> anagrams;
        for (string str : strs) {
            string word = str;
            sort(word.begin(), word.end());
            anagrams[word].push_back(str);
        }
        for (auto x = anagrams.begin(); x != anagrams.end(); x++) {
            res.push_back(x->second);
        }
        return res;
    }
};
