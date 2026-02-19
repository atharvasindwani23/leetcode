class Solution {
public:
    bool canShip(const vector<int>& weights, int days, int cap) {
        int usedDays = 1;
        long long cur = 0;

        for (int w : weights) {
            if (w > cap) return false; // impossible
            if (cur + w <= cap) {
                cur += w;
            } else {
                usedDays++;
                cur = w;
                if (usedDays > days) return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0, hi = 0;
        for (int w : weights) {
            lo = max(lo, w);   // at least the heaviest package
            hi += w;           // at most ship all in one day
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canShip(weights, days, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

