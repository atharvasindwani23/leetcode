class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    std::set<int> vec1;
    std::set<int> vec2;
    for (unsigned int i = 0; i < nums1.size(); i++) {
        vec1.insert(nums1[i]);
    }
    for (unsigned int i = 0; i < nums2.size(); i++) {
        vec2.insert(nums2[i]);
    }
    std::vector<int> returner;
    for (unsigned int i : vec1) {
        for (unsigned int j : vec2) {
            if (i == j) {
            returner.push_back(i);
            }
        }
    }
    return returner;
    }
};
