class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::vector<int> copier(nums.size());
         for (unsigned int i = 0; i < nums.size(); i++) {
          copier[i] = nums[i];
         }
         int refined_k = k % nums.size();
        for (unsigned int i  = 0; i < nums.size() - refined_k; i++) {
           // int temp = nums[i + k];
            nums[i + refined_k] = copier[i];
            //nums[i] = temp;
        }
        for (unsigned int i = nums.size() - refined_k; i < nums.size(); i++) {
           // int temp = nums[i + k - nums.size()];
            nums[i + refined_k - nums.size()] = copier[i];
           // nums[i] = temp;
        }
    }
};
