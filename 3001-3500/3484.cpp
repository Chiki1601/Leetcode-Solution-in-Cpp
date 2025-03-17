class Spreadsheet {
private:
    vector<vector<int>> sp;
public:
    Spreadsheet(int rows) {
        sp = vector<vector<int>>(rows + 1, vector<int>(26));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sp[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int get_val(const string& cell) {
        if(isdigit(cell[0])) 
            return stoi(cell);

        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)); 
        return sp[row][col];
    }

    int getValue(string formula) {
        formula = formula.substr(1);
        size_t plus = formula.find('+');
        return get_val(formula.substr(0, plus)) + get_val(formula.substr(plus + 1));
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
