class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>returner;
        std::map<int, int> frequency;
        for (int i : nums) {
            frequency[i]++;
        }
        std::map<int, vector<int>>magic_array;
        for (auto x : frequency) {
            magic_array[x.second].push_back(x.first);
        }
       for (int i = nums.size(); i >= 1; i--) {
          for (int num : magic_array[i]) {
            returner.push_back(num);
            if (returner.size() == k) {
                return returner;
            }
          }
        }
        return returner;
    }
    //once we have a map with numbers and their corresponding frequencies
    //we're just printing out the Kth largest elements
    // {1:3, 2:2, 3:1}
    // {1,2,2,1,3,4} -> {1->3,4  2->1,2}
};
