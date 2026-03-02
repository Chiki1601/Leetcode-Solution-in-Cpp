class Solution {
public:
       int minimumOR(vector<vector<int>>& grid) {
        int res = 0;
        for (int bi = 20; bi >= 0; --bi) {
            int b = 1 << bi;
            int mask = res | (b - 1);
            for (auto& r : grid) {
                bool row_all_bad = true;
                for (int a : r) {
                    if ((a & mask) == a) {
                        row_all_bad = false;
                        break;
                    }
                }
                if (row_all_bad) {
                    res |= b;
                    break;
                }
            }
        }
        return res;
    }
};
