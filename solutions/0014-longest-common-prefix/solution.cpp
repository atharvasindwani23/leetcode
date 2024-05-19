class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix = "";
        std::string shortest = shortestWordReturner(strs);
        int min = 10000000;
        for (std::string str : strs) {
            for (unsigned int i = 0; i < shortest.size(); i++) {
                if (str[i] != shortest[i]) {
                    if (min > i) {
                        min = i;
                    }
                   //return shortest.substr(0, i);
                }
            }
        }
        return shortest.substr(0, min);
    }
     string shortestWordReturner(vector<string>& strs) {
        int min = 10000000000;
        std::string returner;
        for (std::string str : strs) {
           if (min > str.size()) {
            min = str.size();
            returner = str;
           }
        }
        return returner;
    }
};
