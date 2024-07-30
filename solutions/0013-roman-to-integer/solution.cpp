class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> roman;
        int returner = 0;
        roman['I'] = 1;
         roman['V'] = 5;
        roman['X'] = 10;
         roman['L'] = 50;
         roman['C'] = 100;
         roman['D'] = 500;
         roman['M'] = 1000;
        for (unsigned int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (s[i] == 'I' && s[i + 1] == 'V' || s[i] == 'I' && s[i + 1] == 'X') {
                returner -= 2;
            }
            if (s[i] == 'X' && s[i + 1] == 'L' || s[i] == 'X' && s[i + 1] == 'C') {
                returner -= 20;
            }
            if(s[i] == 'C' && s[i + 1] == 'D' || s[i] == 'C' && s[i + 1] == 'M') {
                returner -= 200;
            }
          returner += roman[ch];
        }
        return returner;
    }
};
