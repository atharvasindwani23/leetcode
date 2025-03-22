class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::set<int> unique;
        std::vector<int>returner;
        for (int i : nums) {
            unique.insert(i);
        }
        for (unsigned int i  = 1; i <= nums.size(); i++) {
            if (!unique.contains(i)) {
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
