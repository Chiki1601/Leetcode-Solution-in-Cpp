class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[0]< b[0]; });
        int ans = 0;
        for (int i = 1; i < A.size(); ++i) ans = max(ans, A[i][0] - A[i - 1][0]);
        return ans;
    }
};
