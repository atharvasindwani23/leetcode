class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            string res = "";
            //we know its a prefix, so the string should be starting from 0
            int len = INT_MAX;
            for (string str : strs) {
                len = min(len, (int)str.size());
            }
            for (int i = len; i >= 0; i--) {
                string word = strs[0].substr(0, i);
                bool b = false;
                for (string str : strs) {
                    if (word != str.substr(0, i)) {
                        b = true;
                    }
                }
                if (!b) {
                    return word;
                }
            }
            return res;
    }
};
