class Solution {
public:
    int numberOfSpecialChars(string word) {
       int res = 0;
       unordered_map<int,int> freq;

       for (char ch: word) {
        freq[(int)ch]++;
       }

       for (auto x = freq.begin(); x != freq.end(); x++) {
            cout << "helo";
            int val = x->first;
            if (freq.count(val + 32)) {
                res += 1;
            }
       }
       return res;


//difference between lowercase and uppercase constituents is 26
    }


    //"" -> 0
    // "abc" -> 0
    //"ABC" -> 0
    //aAbBcC -> 3
    //a -> x
    //A -> x + const
    //aAA -> 1


};
