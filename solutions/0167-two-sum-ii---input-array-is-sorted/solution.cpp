class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>returner(2);
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[right] + numbers[left] == target) {
                returner[1] = right + 1;
                returner[0] = left + 1;
                return returner;
            } else if (numbers[right] + numbers[left] < target) {
                 left++;
            } else {
                right--;
            }
        }
        return returner;
    }
};
// [2 7 11 15] -> 
