class Solution {
public:
    int getLeastFrequentDigit(int n) {
        // Frequency array for digits 0-9
        vector<int> f(10, 0);

        // Count digit frequencies
        while (n > 0) {
            int d = n % 10;
            f[d]++;
            n /= 10;
        }

        // Find least frequent digit (tie -> smaller digit)
        int ans = -1, minu = INT_MAX;
        for (int d = 0; d <= 9; d++) {
            if (f[d] > 0) {
                if (f[d] < minu || (f[d] == minu && d < ans)) {
                    minu = f[d];
                    ans = d;
                }
            }
        }

        return ans;
    }
};
