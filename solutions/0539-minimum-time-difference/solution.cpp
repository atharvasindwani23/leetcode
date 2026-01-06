class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> total_minutes;

        for (int i = 0; i < timePoints.size(); i++) {
            string time = timePoints[i];

            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3));

            total_minutes.push_back(60 * hours + minutes);
        }
        sort(total_minutes.begin(), total_minutes.end());

        int firstMin = INT_MAX;

        for (int i = 1; i < total_minutes.size(); i++) {
            firstMin = min(firstMin, total_minutes[i] - total_minutes[i - 1]);
        }

        return min(firstMin, 24 * 60 - total_minutes.back() + total_minutes.front());
    }

    //logic is to convert everything in minutes sort it and then look at the difference between everything. since time is circular the only difference you will really care about is the one between the last and the first element.
};
