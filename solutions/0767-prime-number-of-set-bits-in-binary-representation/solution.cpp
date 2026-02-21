class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; i++) {
            int num1 = numberOfOnes(i);
            result += prime(num1);
        }
        return result;
    }

    int numberOfOnes(int n) {
        std::string s = std::bitset<32>(n).to_string();
        int count = 0;
        for (char ch : s) {
            if (ch == '1') {
                count++;
            }
        }
        return count;
    }

    bool prime(int number) {
        int factor = 0;
        for (int i = 1; i <= number; i++) {
            if (number % i == 0) {
                factor++;
            }
        }
        return factor == 2;
    }



    //how do i convert an int into its binary representation
    //one would be counting the number of ones a number has in a binary representation
    //second would be checking if that number in itself is prime or not

};
