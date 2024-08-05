#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int returner = 0;
        int odd_count = 0;
        unordered_map<int, int> count_map;
        count_map[0] = 1;  // to handle the case where we have exactly k odd numbers from the start
        
        for (int num : nums) {
            odd_count += num % 2;
            if (count_map.find(odd_count - k) != count_map.end()) {
                returner += count_map[odd_count - k];
            }
            count_map[odd_count]++;
        }
        
        return returner;
    }
};

