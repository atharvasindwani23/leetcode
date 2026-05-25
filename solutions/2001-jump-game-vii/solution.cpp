class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (s[n - 1] == '1') return false;

        vector<bool> jumps(n, false);
        jumps[n - 1] = true;

        int rightMostUnchecked = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (!jumps[i]) continue;

            int left = max(0, i - maxJump);
            int right = i - minJump;

            // Only scan indices we have not checked before
            right = min(right, rightMostUnchecked);

            for (int j = right; j >= left; j--) {
                if (s[j] == '0') {
                    jumps[j] = true;
                }
            }

            // Everything from left to right has now been processed
            rightMostUnchecked = left - 1;
        }

        return jumps[0];
    }
};
