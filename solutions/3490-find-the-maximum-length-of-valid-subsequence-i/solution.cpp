class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int allOddLength = allOdd(nums);
       int allEvenLength = nums.size() - allOdd(nums);
       vector<int> res(nums.size(), 0);
       for (int i = 0; i < nums.size(); i++) {
            res[i] = nums[i] % 2;
       }
        int alternating = las(res);
        return max(max(allOddLength, allEvenLength), alternating);
    }


    ///three possibilities
    //all odd, all even
    //odd even odd even odd even 
    //basically your goal therefore is to maximize this?
//q is how do we go about this, first two cases can be done in a very simple way of j picking up the elements

    int allOdd(vector<int> nums) {
        int c = 0;
        for (int num : nums) {
            c += (num % 2);
        }
        return c;
    }

    int las(vector<int> s) {
    if (s.empty()) return {};

    std::string result;
    result.push_back(s[0]);

    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] != result.back()) {
            result.push_back(s[i]);
        }
    }

    return result.size();
}
};
