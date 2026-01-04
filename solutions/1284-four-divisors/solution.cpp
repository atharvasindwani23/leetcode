class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res += helper(num);
        }
        return res;
    }

    int helper(int num) {
        int sum = 0;
        int count = 0;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                count++;
                sum += i;
            }
            if (count > 4) {
                break;
            }
        }
        if (count == 4) {
            return sum;
        }
        return 0;
    }

};
