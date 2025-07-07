class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        string res = "";
        priority_queue<pair<int,char>> pq;
        for (auto x = freq.begin(); x != freq.end(); x++) {
            pq.push({x->second, x->first});
        }
        while (pq.size() > 0) {
            auto x = pq.top();
            pq.pop();
            for (int i = 0; i < x.first; i++) {
                res += x.second;
            }
        }
        return res;
    }
};
