class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        set<int> sortedIndices;
        sortedIndices.insert(-1);
        sortedIndices.insert(n);

        long long currentCount = 0;
        for (int t = 0; t < n; ++t) {
            int idx = order[t];
            sortedIndices.insert(idx);
            
            auto it = sortedIndices.find(idx);

            auto left = prev(it), right = next(it);
            long long leftCount = idx - (*left) - 1LL;
            long long rightCount = (*right) - idx - 1LL;
            currentCount += (leftCount + 1) * (rightCount + 1);

            if (currentCount >= k) {
                return t;
            }
        }

        return -1;
    }
};
