class Solution {
public:
    int minFlipsMonoIncr(string s) {
       int ones = 0;
       int flips = 0;
       for (char ch : s) {
            if (ch == '1') {
                ones++;
            } else {
                flips++;
                flips = min(flips, ones);
            }
       }
       return flips;
    }


    //[011001]
    //len(string) - i
};
