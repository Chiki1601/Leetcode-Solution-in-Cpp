class Solution {
    public long[] countStableSubarrays(int[] nums, int[][] queries) {

        int n = nums.length;
        int q = queries.length;

        long[] len = new long[n];
        len[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] <= nums[i]) len[i] = len[i - 1] + 1;
            else len[i] = 1;
        }

        // prefix sum of lengths
        long[] pref = new long[n + 1];
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + len[i];

        // index[i] = farthest extension of the non-decreasing streak starting at i
        int[] index = new int[n];
        int idx = n - 1;
        index[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) index[i] = idx;
            else {
                idx = i;
                index[i] = idx;
            }
        }

        long[] ans = new long[q];

        for (int qi = 0; qi < q; qi++) {
            int l = queries[qi][0];
            int r = queries[qi][1];

            // find where streak from l breaks
            int right = Math.min(index[l], r);

            long diff = right - l + 1;
            long sum = diff * (diff + 1) / 2;

            long after = 0;
            if (right < r) {
                after = pref[r + 1] - pref[right + 1];
            }

            ans[qi] = sum + after;
        }

        return ans;
    }
}


# Code
```C++

class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int q = queries.size();

        vector<long long> len(n);
        len[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] <= nums[i]) len[i] = len[i - 1] + 1;
            else len[i] = 1;
        }

        // prefix sum of len[]
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + len[i];
        }

        // index[i] = farthest index where non-decreasing streak starting at i continues
        vector<int> index(n);
        int idx = n - 1;
        index[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) index[i] = idx;
            else {
                idx = i;
                index[i] = idx;
            }
        }

        vector<long long> ans(q);

        for (int qi = 0; qi < q; qi++) {
            int l = queries[qi][0];
            int r = queries[qi][1];

            int right = min(index[l], r);

            long long diff = right - l + 1;
            long long sum = diff * (diff + 1) / 2;

            long long after = 0;
            if (right < r) {
                after = pref[r + 1] - pref[right + 1];
            }

            ans[qi] = sum + after;
        }

        return ans;
    }
};
