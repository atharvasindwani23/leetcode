class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string flag = "";
        vector<string> returner;
        for (unsigned int i = 0; i < s.size(); i++) {
            if (i % k == 0 && i != 0) {
                returner.push_back(flag);
                flag = "";
            }
                flag += s[i];
            }
            std::cout << flag.size();
            int temp = flag.size();
            if (flag.size() != k) {
                for (int i = 0; i < k - temp; i++) {
                    flag += fill;
                }
            }
            returner.push_back(flag);
            return returner;
        }
    };
