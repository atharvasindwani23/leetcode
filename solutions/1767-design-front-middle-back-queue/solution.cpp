#include <deque>
using namespace std;

class FrontMiddleBackQueue {
    deque<int> L, R; // queue = L followed by R

    void rebalance() {
        // Keep |L| == |R| OR |L| == |R| + 1
        if (L.size() > R.size() + 1) {
            R.push_front(L.back());
            L.pop_back();
        } else if (L.size() < R.size()) {
            L.push_back(R.front());
            R.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        L.push_front(val);
        rebalance();
    }

    void pushMiddle(int val) {
        // Insert at index n/2 (frontmost middle)
        // If L has one extra, shift its last to R so boundary is the middle position
        if (L.size() > R.size()) {
            R.push_front(L.back());
            L.pop_back();
        }
        L.push_back(val);
        rebalance();
    }

    void pushBack(int val) {
        R.push_back(val);
        rebalance();
    }

    int popFront() {
        if (L.empty() && R.empty()) return -1;

        int ans;
        if (!L.empty()) {
            ans = L.front();
            L.pop_front();
        } else {
            ans = R.front();
            R.pop_front();
        }
        rebalance();
        return ans;
    }

    int popMiddle() {
        if (L.empty() && R.empty()) return -1;

        // frontmost middle is always back(L)
        int ans = L.back();
        L.pop_back();
        rebalance();
        return ans;
    }

    int popBack() {
        if (L.empty() && R.empty()) return -1;

        int ans;
        if (!R.empty()) {
            ans = R.back();
            R.pop_back();
        } else {
            ans = L.back();
            L.pop_back();
        }
        rebalance();
        return ans;
    }
};
