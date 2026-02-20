class RideSharingSystem {
public:

    vector<int> rides;
    vector<int> drivers;
    unordered_set<int> riderIds;

    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        if (!riderIds.count(riderId)) {
            riderIds.insert(riderId);
        }
        rides.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push_back(driverId);
    }
    vector<int> matchDriverWithRider() {
        if (rides.size() == 0 || drivers.size() == 0) {
            cout << "bruh" << endl;
            return {-1, -1};
        }
        while (rides.size() && drivers.size()) {
        int ride = rides[0];
        int driver = drivers[0];
        if (riderIds.count(ride)) {
            drivers.erase(drivers.begin());
            rides.erase(rides.begin());
            return {driver, ride};
        }
        rides.erase(rides.begin());
        }
        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        riderIds.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
