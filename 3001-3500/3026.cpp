class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long ans = LONG_MIN, preSum = 0;
        unordered_map<int, int> mp;
        vector<long> pre;
        for(auto it : nums){
            preSum += it;
            pre.push_back(preSum);
        }
        for(int i = 0 ; i < n ; i++){
            int diff1 = nums[i] - k, diff2 = nums[i] + k;
            if(mp.contains(diff1))
                ans = max(ans, pre[i] - pre[mp[diff1]] + diff1);
            if(mp.contains(diff2))
                ans = max(ans, pre[i] - pre[mp[diff2]] + diff2);
            if(mp.contains(nums[i]))
                mp[nums[i]] = pre[i] < pre[mp[nums[i]]] ? i : mp[nums[i]];
            else
                mp[nums[i]] = i;
        }
        return ans != LONG_MIN ? ans : 0;
    }
};
