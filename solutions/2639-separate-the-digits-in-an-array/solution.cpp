class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        reverse(nums.begin(), nums.end());
        for (int num : nums) {
            int copy = num;
            while (copy) {
                int digit = copy % 10;
                copy = copy / 10;
                cout << digit << endl;
                result.push_back(digit);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
