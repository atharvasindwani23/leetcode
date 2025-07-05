class Solution {
public:
    int findLucky(vector<int>& arr) {
     std::map<int,int> freq;
     for (int i : arr) {
        freq[i]++;
     }
     int maxi = -1;
     for (int i : arr) {
        if (freq[i] == i) {
            maxi = max(maxi, i);
        }
     }
     return maxi;
    }
};
