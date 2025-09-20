class Solution {
public:
    string longestPalindrome(string s) {
        string curr = "";
        for (int i = 0; i < s.size(); i++) {
            string greater = oddLengthPal(s, i);
            if (greater.size() < evenLengthPal(s,i).size()) {
                greater = evenLengthPal(s,i);
            }
            if (curr.size() < greater.size()) {
                curr = greater;
            }
        }
        return curr;
    }

    string oddLengthPal(string s, int idx) {
        int upper = idx + 1;
        int lower = idx - 1;
        while (upper < s.size() && lower >= 0) {
            if (s[upper] == s[lower]) {
                upper++;
                lower--;
            } else {
                break;
            }
        }
        return (s.substr(lower + 1, upper - lower - 1));
    }

    string evenLengthPal(string s, int idx) {
        int upper = idx;
        int lower = idx - 1;
        while (upper < s.size() && lower >= 0) {
            if (s[upper] == s[lower]) {
                upper++;
                lower--;
            } else {
                break;
            }
        }
        return (s.substr(lower + 1, upper - lower - 1));
    }


};
