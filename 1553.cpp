class Solution {
    unordered_map<int, int> m;
public:
    int minDays(int n) {
        if (n <= 1) return n;
        if (m.count(n)) return m[n];
        return m[n] = 1 + min(minDays(n / 3) + n % 3, minDays(n / 2) + n % 2);
    }
};
