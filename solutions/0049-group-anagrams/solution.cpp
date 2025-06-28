class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<string, vector<string>> anagrams;
        vector<vector<string>> returner;
        for (string str: strs) {
            string word = str;
            sort(word.begin(), word.end());
            anagrams[word].push_back(str);
        }
        for (auto x = anagrams.begin(); x!= anagrams.end(); x++) {
            returner.push_back(x->second);
        }
        return returner;
    }
    //anagrams are essentially strings with the exact same length and frequency of each character
    // 123, 321 => 123, 123. 
    //anarams will have a special property which is => upon sorting theyll be equal
    //o(n^3) => complexity
    //hashMap => [][][][] => key = sorted string, value be the anagram which upon sorting matches the key
    //at the end ill just print out the values
    // [eat, tea, pea, eap]
    // aet-> [eat, tea], aep -> [pea, eap]
};
