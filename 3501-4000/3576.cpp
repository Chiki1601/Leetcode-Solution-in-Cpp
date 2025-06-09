class Solution {
public:
    int solve(vector<int> a, int target) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != target) {
                cnt++;
                a[i] = -a[i];
                a[i + 1] = -a[i + 1];
            }
        }
        // If last element matches target, return flips; otherwise no solution
        return (a[n - 1] == target ? cnt : INT_MAX);
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        // Try making all 1s or all -1s
        return solve(nums, 1) <= k || solve(nums, -1) <= k;
    }
};
