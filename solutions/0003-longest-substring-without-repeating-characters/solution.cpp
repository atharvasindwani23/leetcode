class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      std::string returner = "";
      int left = 0;
      int right = 1;
      int max = 0;
      int flag = 0;
      if (s.size() == 0) {
        return 0;
      }
      if (s.size() == 1) {
        return 1;
      }
      returner += s[left];
      while (right < s.size()) {
        if(!present(returner, s[right])) {
            returner += s[right];
            std::cout << returner << std::endl;
            right++;
        } else {
            flag = 1;
            if (max < returner.size()) {
                max = returner.size();
                std::cout << max << std::endl;
            }
         returner = returner.substr(1);
         left++;
        }
     //max will not be updated once it breaks out of the while loop         
      }
      if (max < returner.size()) {
        max = returner.size();
      }
      return max;
    }
    bool present(string s, char ch) {
        for (char c : s) {
            if (c == ch) {
                return true;
            }
        }
        return false;
    }
};
