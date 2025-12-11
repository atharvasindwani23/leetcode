class Solution {
public:

    bool validIp(string s) {
        if (s.size() == 1) {
            return true;
        }

        if (s.size() > 3 || s[0]== '0') {
            return false;
        }
        int num = stoi(s);
        if (num > 255) {
            return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        int len = s.size();

        vector<string> ipAdresses;

        if (len > 12) {
            return {};
        }

        for (int i = 1; i <=3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (i + j + k < len && i + j + k + 3 >= len) {
                    string first = s.substr(0, i);
                    string second = s.substr(i, j);
                    string third = s.substr(i + j, k);
                    string fourth = s.substr(i + j + k);
                    if (validIp(first) && validIp(second) && validIp(third) && validIp(fourth)) {
                        ipAdresses.push_back(first + "." + second + "." + third + "." + fourth);
                    }
                }
                }
            }
        }
        return ipAdresses;
    }
};
