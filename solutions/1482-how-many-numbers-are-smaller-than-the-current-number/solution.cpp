class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::vector<int>returner;
        std::vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        // [1 2 2 3] -> map[1] => 0, map[2] => 1, map[2]
        std::map<int,int> mapper;
        for (unsigned int i  = 0; i < temp.size(); i++) {
            if (mapper.count(temp[i]) == 0) {
            mapper[temp[i]] = i;
            }
         }
         for (int i : nums) {
            returner.push_back(mapper[i]);
         }
         return returner;
    }
};
// [4 7 1 0] -> [2, 3, 1, 0]
//note: that we shouldnt compare the same element with itself 
// [] -> []
// O(n^2), O(n)
// for (every i in nums); 
// for (every j in nums); -> i > j -> count++;
//brute force method
