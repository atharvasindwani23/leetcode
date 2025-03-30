class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       set<int> unique;
       int first = 0;
       int next = 1;
       unique.insert(nums[first]);
       while (next < nums.size()) {
           if (unique.contains(nums[next]) && next - first <=k) {
            std::cout << next << std::endl;
            std::cout << first << std::endl;
            return true;
           }
           while (next - first > k) {
            std::cout << next << std::endl;
            std::cout << first << std::endl;
            std::cout << "nigger?" << std::endl;
            unique.erase(nums[first]);
            first++;
           }
           if (!unique.contains(nums[next])) {
            unique.insert(nums[next]);
            next++;
           }
       }
       return false;
    }
};
