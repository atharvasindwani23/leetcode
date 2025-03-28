class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        int first = 0;
        int next = 1;
        int maxLength = 0;
        set<int> unique;
        unique.insert(s[first]);
 
        while (next < s.size()) {
         if (unique.contains(s[next])) {
           unique.erase(s[first]);
           first++;
         } else {
            unique.insert(s[next]);
            maxLength = max(maxLength, next - first + 1);
            next++;
         }
        }
        return maxLength;
    }
};


// b a c d a e ->   //two pointers 
// a b c d
// a b 
// a a
// a
// ""

//

