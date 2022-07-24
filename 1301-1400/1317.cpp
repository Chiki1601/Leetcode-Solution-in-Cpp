class Solution {
    bool hasZero(int n) {
        for (; n; n /= 10) {
            if (n % 10 == 0) return true;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        for (; hasZero(a) || hasZero(n - a); ++a);
        return { a, n - a };
    }
};
