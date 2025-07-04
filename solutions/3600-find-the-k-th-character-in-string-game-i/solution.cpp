class Solution {
public:
    char kthCharacter(int k) {
       string og_string = "a";
       while (og_string.size() <= k) {
        string replacement = helper(og_string);
        cout << helper(og_string) << endl;
        og_string += replacement;
        cout << og_string << endl;
       }
       return og_string[k - 1];
    }

    string helper(string og_string) {
        string res = "";
        for (int i  = 0; i < og_string.size(); i++) {
            int ascii = (int)(og_string[i]) + 1;
            res += (char)ascii;
        }
        return res;
    }
};
