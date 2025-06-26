class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> returner;
        for (int i = left; i <= right; i++) {
            if (div(digits(i), i)) {
                returner.push_back(i);
            }
        }
        return returner;
    }

    vector<int> digits(int num) {
        int temp = num;
        vector<int> digit;
        while (temp != 0) {
            int dig = temp % 10;
            temp = temp / 10;
            digit.push_back(dig);
        }
        return digit;
    }
    bool div(vector<int> digits, int num) {
        for (int n : digits) {
            if (n == 0) {
                return false;
            }
            if (num % n != 0) {
                return false;
            }
        }
        return true;
    }

};
