class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        return (x == (int)numberReverser(x));
        
    }
    long numberReverser(int n) {
         long reversedNumber = 0;

    while (n > 0) {
        long digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
        n = n / 10;
    }

    return reversedNumber;
}

};
