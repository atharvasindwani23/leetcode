class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
       int k = needle.size();
       int ptr = 0;
       while (ptr < haystack.size()) {
        string comparer = haystack.substr(ptr, k);
        if (comparer == needle) {
            return ptr;
        } else {
          ptr++;
        }
       }
       return -1;
    }

    //need to check where one substr is directly contained within another
    // so basically needle should be contained within haystack
    //covered a base case good
    // some sort of a two ptr technique? just a bit unsure of the ds to use here
    // one logic can be that since the entire string needs to be contained we can wait to see where the first character is matching
    // brute force soln is obv O(n^2)
};
