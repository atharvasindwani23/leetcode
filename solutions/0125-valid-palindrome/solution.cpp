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
    for (char& c : updated) {
         c = std::tolower(static_cast<unsigned char>(c));
    }
    std::string empty = "";
    for (int i = updated.size() - 1; i >= 0; i--) {
        empty += updated[i];
    }
    std::cout << empty << std::endl;
    std::cout << updated;
    return (empty == updated);
    }
};
