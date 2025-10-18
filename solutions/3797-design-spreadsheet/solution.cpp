class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    unordered_map<string, int> values;
    Spreadsheet(int rows) {
    spreadsheet.resize(rows, std::vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        spreadsheet[row][col] = value;
        values[cell] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        string edited = formula.substr(1);
        int idx = 0;
        for (int i = 0; i < edited.size(); i++) {
            if (edited[i] == '+') {
                idx = i;
            }
        }
        string first = edited.substr(0, idx);
        string second = edited.substr(idx + 1);
        int left = first[0] >= 'A' && first[0] <= 'Z' ? values[first] : stoi(first);
        int right = second[0] >= 'A' && second[0] <= 'Z' ? values[second] : stoi(second);
        return left + right;
    }

};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
