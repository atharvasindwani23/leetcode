class Solution {
public:
    string reverseVowels(string s) {
        std::string returner; 
        int flag = s.size() - 1;
        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ) {
                for (unsigned int j  = flag; j >= 0; j--)  {
                    if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U') {
                        returner += s[j];
                        flag = j - 1;
                        break;
                    }
              }
            } else {
            returner += s[i];
            }
        }
        return returner;
    }
};
