class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    for (unsigned int i  = 0; i < matrix.at(0).size(); i++) {
        int temp = i;
        int count = 0;
        while (count < matrix.size()) {
        try {
        if (matrix.at(0).at(i) != matrix.at(count).at(temp)) {
            std::cout << "huh";
            return false;
        }
        count++;
        temp++;
        } catch(...){
            break;
        }
        }
    }
    for (unsigned int i = 1; i < matrix.size(); i++) {
        int temp = i;
        int count = 0;
        while (count < matrix.size()) {
        try {
        if (matrix.at(i).at(0) != matrix.at(temp).at(count)) {
            return false;
        }
        count++;
        temp++;
        } catch(...){
            break;
        }
    }
    }
    return true;
    }
};
