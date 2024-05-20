class Solution {
public:
    int mySqrt(int x) {
        int special_i = 0;
        for (unsigned int  i = 0; i <= x; i++) {
              if (i * i <= x) {
                special_i = i;
            } else {
                break;
            }
        }
        return special_i;
    }
};
