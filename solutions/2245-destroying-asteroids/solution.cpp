class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        for (int asteroid : asteroids) {
            minHeap.push(asteroid);
        }

        long long currMass = mass;

        while (!minHeap.empty()) {
            long long smallest = minHeap.top();

            if (currMass < smallest) {
                return false;
            }

            currMass += smallest;
            minHeap.pop();
        }

        return true;
    }
};
