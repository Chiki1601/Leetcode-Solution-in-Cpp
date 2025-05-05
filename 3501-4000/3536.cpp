class Solution {
public:
    int maxProduct(int n) {
        vector <int> digs;
        while (n > 0) {
            digs.push_back(n%10);
            n /= 10;
        }
        sort(digs.begin(), digs.end());
        return digs[digs.size()-1] * digs[digs.size()-2];
    }
};
