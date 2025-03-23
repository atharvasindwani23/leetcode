class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> bigArray;
        for (int i : nums1) {
            bigArray.push_back(i);
        }
        for (int i : nums2) {
            bigArray.push_back(i);
        }
        sort(bigArray.begin(), bigArray.end());
        if (bigArray.size() % 2 != 0) {
            return (bigArray[bigArray.size() / 2]);
        } else {
            double sum = 0;
            sum = bigArray[bigArray.size() / 2] + bigArray[bigArray.size() / 2 - 1];
            return (sum / 2);
        }
        return -1;
    }
};
