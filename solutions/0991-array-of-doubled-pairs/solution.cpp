class Solution {
public:
   bool canReorderDoubled(vector<int>& arr) {
    std::unordered_map<int, int> freq;
    
    // Count frequencies
    for (int x : arr) {
        freq[x]++;
    }
    
    // Sort by absolute value to handle negative and positive numbers
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
    
    // Try to pair each element with its double
    for (int x : arr) {
        if (freq[x] == 0) continue;  // Already paired
        
        if (freq[2 * x] == 0) return false;  // No pair available
        
        // Pair x with 2 * x
        freq[x]--;
        freq[2 * x]--;
    }
    
    return true;
}

};
