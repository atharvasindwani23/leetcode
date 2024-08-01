class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> returner;
         int first = 0;
         int last = numbers.size() -1;
        while (first < last) {
            if (numbers[first] + numbers[last] == target) {
                returner.push_back(first + 1);
                returner.push_back(last + 1);
                return returner;
            } else if (numbers[first] + numbers[last] > target) {
                last--;
            } else {
                first++;
            }
        }
        return returner;
    }
};
