class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0;
        for (int i  = 0; i < points.size() - 1; i++) {
            sum += max(abs(points[i + 1][1] - points[i][1]), abs(points[i + 1][0] - points[i][0]));
        }
        return sum;
    }
    
};
