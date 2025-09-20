class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        for (int i = 0; i < min(word1.size(), word2.size()); i++) {
            cout << "BRUH" << endl;
            res += word1[i];
            res += word2[i];
        }
        string word = word2;
        if (word1.size() > word2.size()) {
            word = word1;
        }
        int x = min(word1.size(), word2.size());
        cout << x << endl;
        cout << word.size() << endl;
        for (int i = x; i < word.size(); i++) {
            cout << "meow?" << endl;
            res += word[i];
        }
        return res;
    }
};
