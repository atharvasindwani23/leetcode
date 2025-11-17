class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> positions;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                positions.push_back(i);
            }
        }

        for (int i = 1; i < positions.size(); i++) {
            cout << positions[i] << endl;
            if (positions[i] - positions[i - 1] < k + 1) {
                return false;
            }
        }
        return true;
    }
};
