class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        s += " ";
        string res;
        string word;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (word.size() == 0) {
                    continue;
                }
                words.push_back(word);
                word = "";
            }
        }
        reverse(words.begin(), words.end());
        for (string s : words) {
            cout << s << endl;
            res += s + " ";
        }
        return res.substr(0, res.size() - 1);
    }
};
