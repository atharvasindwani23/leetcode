class MyCalendar {
public:
    set<pair<int,int>> bookings;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        if (bookings.size() == 0) {
            bookings.insert({startTime, endTime});
            return true;
        }
        pair<int,int> currBooking = {startTime, endTime};
        auto it = bookings.lower_bound(currBooking);
        auto temp = it;
        // if (it == bookings.end()) {
        //     bookings.insert(currBooking);
        //     return true;
        // }
        //(a,b), (c,d) => max(a,c) < min(b,d)
        --it;
        if (min(endTime,it->second) > max(startTime, it->first) || min(endTime,temp->second) > max(startTime, temp->first)) {
            return false;
        }
        bookings.insert(currBooking);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
