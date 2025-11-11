class Solution {
public:
      int longestSubarray(vector<int>& A) {
        int n = A.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++)
            if (A[i - 1] <= A[i])
                left[i] = left[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (A[i] <= A[i + 1])
                right[i] = right[i + 1] + 1;
        int res = min(n, *max_element(left.begin(), left.end()) + 1);
        for (int i = 1; i < n - 1; i++)
            if (A[i - 1] <= A[i + 1])
                res = max(res, left[i - 1] + 1 + right[i + 1]);
        return res;
    }
};
