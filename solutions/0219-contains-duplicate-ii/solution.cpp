class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mostRecIdx;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            if (mostRecIdx.count(curr)) {
                if (i - mostRecIdx[curr] <= k) {
                    return true;
                }
            }
            mostRecIdx[curr] = i;
        }
        return false; 
    }
    

    //can we do a two pointer approach?
    // do we store the indexes in a sort of a map and then sort?
    // what i mean by that is we make a map<int, vector<int>> if vector<int>.size() >= 2, this means that there are indexes stored
    //we single out the elements which have the vectors whose sizes are greater and then we do something maybe?

    // the problem is the confusion of knowing where to move if two things dont meet
    // say nums[l] != nums[r] now what? which pointer do we move? we don't have enough info on this unfortunately

    //can't sort because thers the index difference constraint
    // what can we do instead?

};
