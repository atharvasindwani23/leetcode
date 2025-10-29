class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        colors.insert(colors.begin(), colors.back());
        colors.push_back(colors[1]);

        int count = 0;

        for (int i = 1; i < colors.size() - 1; i++) {
            int behind = colors[i - 1];
            int ahead = colors[i  +1];
            int curr = colors[i];
            if (behind == ahead && behind != curr) {
                count++;
            }
        }

        return count;
    }
};
