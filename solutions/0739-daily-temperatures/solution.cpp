class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> temps;
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {

            while (!temps.empty() && temps.top().first < temperatures[i]) {
                auto curr = temps.top();
                temps.pop();
                res[curr.second] = i - curr.second;
            }
            temps.push({temperatures[i], i});
        }
        return res;
    }
//stack
//im going to push elements into a stack
//if a stack is not empty AND the current element im iterating through has a higher templrature than the top of the stack; ill pop the top element and ill record the time taken as the difference in the indices; I  WILL KEEP ON DOING THIS until the curr temp im at is < then the top element of the stack    
};
