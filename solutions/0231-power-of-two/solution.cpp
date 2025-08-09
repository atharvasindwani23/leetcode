class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
       while (n % 2 == 0) {
        n = n / 2;
       }
       return (n == 1);
    }

    //basically the trick here is to notice the fact that 2^x = ? where x should be an integer
    //my trick would be to tell it that if it has any factor from 3 uptil n - 1 then its over
};
