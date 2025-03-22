class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::map<int,bool> present;
        for (unsigned int i  = 0; i < nums.size(); i++) {
             present[nums[i]] = true;
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            if (!present[i]) {
                return i;
            }
        }
        return -1;
    } 
};
 // nums.size() == n - 1;
    // are in any order
    // sort the array -> [0 , 1, 3]
    // for (for every element) {
    // its index and its value
    //i != arr[i]
    // [0 1 2] -> return nums.size()
    //  O(nlogn) -> ideally should do it one traversal
    // std::map<int, bool> -> default value of false
    // map within the loop -> nums.size() elements nums.size() + 1 -> x.second == false;
