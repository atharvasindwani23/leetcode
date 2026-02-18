class MyCalendar {
public:
    set<pair<int,int>> calendar;

    bool book(int start, int end) {
        auto it = calendar.lower_bound({start, end}); // first interval with start' >= start

        // check overlap with next interval
        if (it != calendar.end() && it->first < end) return false;

        // check overlap with previous interval
        if (it != calendar.begin()) {
            auto prevIt = prev(it);
            if (prevIt->second > start) return false;
        }

        calendar.insert({start, end});
        return true;
    }
};

