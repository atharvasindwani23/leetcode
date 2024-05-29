class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        std::vector<int> sum_vector;
        int max = -99999999999;
        int sum = 0;
        for (unsigned int i = 0; i < gain.size(); i++) {
         sum += gain[i];
         sum_vector.push_back(sum);
        }
        sum_vector.push_back(0);
        for (int i : sum_vector) {
             if (i >= max) {
                max = i;
             }
        }
        return max;
    }
};
