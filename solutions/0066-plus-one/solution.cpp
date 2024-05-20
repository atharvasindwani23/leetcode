class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> edgeReturner(digits.size() + 1);
        int c = 0;
        for (int digit : digits) {
               if (digit == 9) {
                c++;
               }
        }
        if (c == digits.size()) {
        for (unsigned int i = 0; i < digits.size(); i++) {
        edgeReturner[i] = 0;
    }
    //edgeReturner.push_back(3);
    edgeReturner[0] = 1;
    return edgeReturner;
    }
        std::vector<int> returner(digits.size());
        returner = digits;
        if (returner[returner.size() - 1] != 9) {
        returner[returner.size() - 1]++;
        } else {
            for (int i = (int)returner.size() - 1; i >= 0; i--) {
                if (digits[i] == 9) {
                    returner[i] = 0;
                } else {
                    if (i == 0) {
                        returner[0]++;
                    } else {
                    returner[i]++;
                    break;
                }
                }
            }
        }
        return returner;
    }
};
