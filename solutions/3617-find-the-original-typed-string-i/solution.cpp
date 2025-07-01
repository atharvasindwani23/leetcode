class Solution {
public:
    int possibleStringCount(string word) {
        int s = 1;
        for (int i  = 0; i < word.size() - 1; i++) {
             if (word[i] == word[i + 1]) {
                s++;
             }
        }     
        return s;   
    }

    //logic is to figure out the length of the longest common letter substring they can find, then subtract that by 1 add it up and then add 1 at the end, things to keep in mind: number of substrings would be the length of the longest substring which can be formed - 1 [bbb] => valid substrings are bb, bbb [;ength < 2] we dont want to include all the characters so bbb

    ///bbbbccc =>3 + 2 +1 =>6

    ///bbbbcccc
    ///ccc
    // bccc, bbccc, bbbccc, bbbbccc, bbbbc,bbbbcc
};
