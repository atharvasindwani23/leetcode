class NumArray {
public:

//can do it by prefix and suffix if we are really smart
    //make an array input such that input[i] has all the sums from
    vector<int> input;
    NumArray(vector<int>& nums) {
        input.resize(nums.size());  
        input[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            input[i] = input[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        //input[left] = nums[0] + .... nums[left]
        //input[right] = nums[0] + ...................nums[right]
        if (left == 0) {
            return input[right];
        }
      return (input[right] - input[left - 1]);
    }
    //[-2, -2, 1, -4, -2, -3]
    // 0       2           5 
    //is there a way to do this in o(1)
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
