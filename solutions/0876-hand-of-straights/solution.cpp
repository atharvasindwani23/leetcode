class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::map<int, int> freq;
for (int num : hand) freq[num]++; // Count frequencies

for (auto it = freq.begin(); it != freq.end(); ++it) {
    int start = it->first;
    int count = it->second;

    if (count == 0) continue;

    // Try to build a group starting at 'start'
    for (int i = 0; i < groupSize; ++i) {
        if (freq[start + i] < count) return false;
        freq[start + i] -= count;
    }
}
return true;


    }


    //1 2 2 3 4 4 groups of 3 => how do we know if it can be arranged
};
