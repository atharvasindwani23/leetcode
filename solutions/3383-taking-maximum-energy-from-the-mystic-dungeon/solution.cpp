class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        reverse(energy.begin(), energy.end());
        int res = energy[0];
        for (int i = 0; i < k; i++) {
            res = max(res, backtracking(i, energy, k));
        }
        return res;
    }

    int backtracking(int curr_idx, vector<int>& input, int k) {

        int max_sum = input[curr_idx];
        int curr_sum = input[curr_idx];
        for (int i = curr_idx + k; i < input.size(); i+= k) {

            curr_sum += input[i];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }
        }
        return max_sum;
    }

    //figure out max energy,
    //starting point can be anything
    //if things go out of bounds, return curr sum
    // basically you cannot get any more value then you have
    //if you're at positions [energy.size() - k, energy.size() - 1]
    //so these are the maxes which you have and these are the only things you need to work with
    // i store a max variable and i basically ask myself, which is bigger my current max or what i see at idx energy.size() - k - k + max, then i store that as my current_max
};
