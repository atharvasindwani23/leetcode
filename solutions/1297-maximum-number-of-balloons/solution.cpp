class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if (text.size()  < 7) {
            return 0;
        }
        std::map<char,int> freq;
        for (char ch : text) {
            freq[ch]++;
        }
        int balloons = 0;
        bool b = freq['b'] >= 1 && freq['o'] >= 2 && freq['l'] >= 2 && freq['n'] >= 1 && freq['a'] >= 1;
        while (b) {
            balloons++;
            freq['b'] -= 1;
            freq['o'] -= 2;
            freq['n'] -= 1;
            freq['l'] -= 2;
            freq['a'] -= 1;
            b = freq['b'] >= 1 && freq['o'] >= 2 && freq['l'] >= 2 && freq['n'] >= 1 && freq['a'] >= 1;
        }
        return balloons;
    }

    //b's a's l's o's n's [balloon] -> 2l's 2o's per one

};
