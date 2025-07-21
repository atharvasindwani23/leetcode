class Solution {
public:
    string makeFancyString(string s) {
        int left = 0;
        int right = 1;
        s += " ";
        string res = "";
        int sequence = 1;
        while (right < s.size()) {
            if (s[left] == s[right]) {
                sequence++;
                right++;
            } else {
                if (sequence >= 3) {
                    cout << s[left] << endl;
                    cout << s[right] << endl;
                    for (int i = 0; i < 2; i++) {
                        res += s[left];
                    }
                } else {
                    for (int i = 0; i < sequence; i++) {
                        res += s[left];
                    }
                }
                left = right;
                right++;
                sequence = 1;
            }
         }
         return res;
    }

};
