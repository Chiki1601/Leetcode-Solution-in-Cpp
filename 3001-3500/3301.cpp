class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(), maximumHeight.rend());
        int now = maximumHeight[0];
        long long sum = 0;  // Change to long long
        int n = maximumHeight.size();
        for (int i = 0; i < n; ++i) {
            now = min(now, maximumHeight[i]);
            if (now <= 0) {
                return -1;
            }
            sum += now;
            now -= 1;
        }
        return sum;
    }
};
