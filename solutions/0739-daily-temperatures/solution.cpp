class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);

        stack<pair<int,int>>temps;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!temps.empty() && temperatures[i] > temps.top().first) {
                auto curr = temps.top();
                temps.pop();
                int idx = curr.second;
                result[idx] = i - idx;
            }
            temps.push({temperatures[i], i});
        }
        return result;
    }
};
