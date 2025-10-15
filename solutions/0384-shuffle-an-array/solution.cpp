class Solution {
public:
    vector<int> finalVector;
    set<int> seen;
    Solution(vector<int>& nums) {
        finalVector = nums;
    }
    
    vector<int> reset() {
        return finalVector;
    }
    
    vector<int> shuffle() {
        vector<int> copy = finalVector;
        seen.clear();
        for (int i = 0; i < copy.size(); i++) {
            int idx = getRandomIdx(copy.size(), seen);
            copy[i] = finalVector[idx];
            seen.insert(idx);
        }
        return copy;
    }
    int getRandomIdx(int n, set<int>& seen) {
        int idx = rand() % n;
        for (int n : seen) {
            cout << n << endl;
            cout << "printing n" << endl;
        }

        while (seen.count(idx) != 0) {
            idx = rand() % n;
            cout << idx << endl;
        }
        return idx;
    }
 };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
