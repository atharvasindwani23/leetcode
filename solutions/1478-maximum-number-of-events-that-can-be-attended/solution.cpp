class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end()); 
    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0, n = events.size(), day = 0, res = 0;
    
    int last_day = 0;
    for (auto& event : events) {
        last_day = max(last_day, event[1]);
    }

    for (day = 1; day <= last_day; ++day) {
        while (i < n && events[i][0] == day) {
            pq.push(events[i][1]);
            ++i;
        }

        while (!pq.empty() && pq.top() < day) {
            pq.pop();
        }

        if (!pq.empty()) {
            pq.pop();
            ++res;
        }
    }

    return res;
}
};
