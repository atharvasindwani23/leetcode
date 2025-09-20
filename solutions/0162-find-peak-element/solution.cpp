class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        if (nums[0] >= nums[1]) {
            return 0;
        }
        if (nums[nums.size() - 1] >= nums[nums.size() - 2]) {
            return nums.size() - 1;
        }
        //we know we need to use binary search the q is how, 
        //im asking myself what do i really need? [1,2,3,1], if (curr < curr + 1 && curr > curr - 1) {return curr}
        //else if curr < curr + 1 -> we then know that curr + 1 has a chance of being a pivot so we shift the stuff to that

        int lower = 0;
        int upper = nums.size() - 1;
        while (lower <= upper) {
            int curr = (lower + upper) / 2;
            cout << lower << endl;
            cout << upper << endl;
            if (nums[curr] >= nums[curr - 1] && nums[curr] >= nums[curr + 1]) {
                return curr;
            } else if (nums[curr] < nums[curr + 1]) {
                lower = curr;
            } else {
                upper = curr;
            }
        }
        return -1;
    }


    // peak is essentially the element which is strictly greater than neighbours
    //should be easy
};
