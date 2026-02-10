class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        set<pair<long long,int>> st;
        int l = 0;
        long long cnt = 0;
        for (int r = 0; r < n; r++) {
            st.insert({nums[r],r});
            while (!st.empty() && l <= r &&(((*st.rbegin()).first - (*st.begin()).first) *(1LL)*(r - l + 1) > k)) {
                st.erase({nums[l],l});
                l++;
            }
            int maxi = (*st.rbegin()).first;
            int mini = (*st.begin()).first;
            long long cost = 1LL * (maxi - mini) * (r - l + 1);
            if (cost <= k) {
                long long len = r - l + 1;
                cnt += len;
            }
        }

        return cnt;
    }
};
