class DataStream {
public:
    int count = 0;
    int value = 0;
    int k = 0;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if (num == value) {
            count++;
        } else {
            count = 0;
        }
        return (count >= k);
    }

    //just store a count of the number of consec elements, you see
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
