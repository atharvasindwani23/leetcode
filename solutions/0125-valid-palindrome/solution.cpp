class Solution {
public:
    bool isPalindrome(string s) {
        std::string updated = "";
        for (char ch : s) {
            if (!std::isalpha(static_cast<unsigned char>(ch)) && !std::isalnum(static_cast<unsigned char>(ch))) {

            } else {
                updated += ch;
            }
        }
         for (char &c : updated) {
        c = std::tolower(static_cast<unsigned char>(c));
        }
        int f = 0;
        int l = updated.size() - 1;
        while (f <= l) {
            if (updated[f] == updated[l]) {
                f++;
                l--;
            } else {
                return false;
            }
        }
        return true;
    }
};
