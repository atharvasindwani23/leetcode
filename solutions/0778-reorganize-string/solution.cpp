class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> freq;
        string res = "";
        priority_queue<pair<int,char>> pq;
        for (char ch : s) {
            freq[ch]++;
        }
        for (auto x = freq.begin(); x != freq.end(); x++) {
            pq.push({x->second, x->first});
        }

        while (pq.size() > 1) {
            auto one = pq.top();
            pq.pop();
            auto two = pq.top();
            pq.pop();
            one.first--;
            two.first--;
            res += one.second;
            res += two.second;
            if (one.first > 0) {
                pq.push(one);
            }
            if (two.first > 0) {
                pq.push(two);
            }
        }
        if (pq.size() == 1) {
            auto x = pq.top();
            if (x.first > 1) {
                return "";
            }
            return res + x.second;
        }
        return res;
    }
};
