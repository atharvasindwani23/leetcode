class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0;
        for (int i : apple) {
            apples += i;
        }
        int count = 0;
        int boxCapacity = 0;
        std::sort(capacity.begin(), capacity.end());
        for (int i = capacity.size() - 1; i >= 0; i--) {
             if (boxCapacity < apples) {
                boxCapacity += capacity[i];
                count++;
             } else {
                return count;
             }
        }
        return capacity.size();
    }
};
