class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        map<pair<int,int>, int> difference;
        vector<vector<int>> res;
        int minimum = 1000000;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            pair<int,int> curr = {arr[i], arr[i + 1]};
            difference[curr] = arr[i + 1] - arr[i];
            minimum = min(minimum, difference[curr]);
        }

        for (auto x = difference.begin(); x != difference.end(); x++) {
            if (x->second == minimum) {
                res.push_back(pairToVector(x->first));
            }
        }
        return res;
    }

    vector<int> pairToVector(pair<int,int> input) {
        vector<int> res;
        res.push_back(input.first);
        res.push_back(input.second);
        return res;
    }
};
