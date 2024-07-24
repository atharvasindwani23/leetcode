class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
            for (unsigned int i = 0; i < nums.size(); i++) {
                if (nums.at(i) != val) {
                  count++;
                }
            }
            for (unsigned int i = 0; i < nums.size(); i++) {
                if (nums.at(i) == val) {
                    nums.at(i) = 51;
                }
            }
             std::sort(nums.begin(), nums.end());
             return count;
    }

};
