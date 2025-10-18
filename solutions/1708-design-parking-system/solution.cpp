class ParkingSystem {
public:
    int bigSlots = 0;
    int mediumSlots = 0;
    int smallSlots = 0;
    ParkingSystem(int big, int medium, int small) {
        bigSlots = big;
        mediumSlots = medium;
        smallSlots = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1 && bigSlots > 0) {
            bigSlots--;
            return true;
        }
        if (carType == 2 && mediumSlots > 0) {
            mediumSlots--;
            return true;
        }
        if (carType == 3 && smallSlots > 0) {
            smallSlots--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
