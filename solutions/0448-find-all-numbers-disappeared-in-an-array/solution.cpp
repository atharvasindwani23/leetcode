class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       std::vector<int> returner;
       std::map<int,int> freq;
       for (int i : nums) {
        freq[i]++;
       }
       for (int i = 1; i <= nums.size(); i++) {
        if (freq[i] == 0) {
            returner.push_back(i);
        }
       }
       return returner;
    }
};


// for (every element in numns) {
//    populate map-> set value to true
//}
//  map != duplicates
//
