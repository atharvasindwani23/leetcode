class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> present;
        for (int num : nums) {
            present[num] = true;
        }
        int res = 0;
        vector<int> starting_vals;
        for (auto x : present) {
            if (present[x.first - 1] == false) {
                starting_vals.push_back(x.first);
                cout << x.first << endl;
            }
        }
        for (int num : starting_vals) {
            int t = num;
            while (present[t]) {
                t++;
            }
            res = max(res, t - num);
        }
        return res;
    }
};
