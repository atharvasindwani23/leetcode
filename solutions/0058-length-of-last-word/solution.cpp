class Solution {
public:
    int lengthOfLastWord(string s) {
       std::vector<std::string> vec;
       s = s + " ";
       std::string word = "";
       for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            word += s[i];
        } else {
            if (word == "") {

            } else {
            vec.push_back(word);
            word = "";
        }
        }
       }
       return vec[vec.size() - 1].size();
    }
};
