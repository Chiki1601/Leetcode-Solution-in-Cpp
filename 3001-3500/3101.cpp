class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        int bg = 0;
        long long ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                long long len = i - bg;
                ans += (long long)(len * (len + 1) * 1ll) / 2;
                bg = i;
            }
        }
        long long len = nums.size() - bg;
        ans += (long long)(len * (len + 1) * 1ll) / 2;
        return ans;
    }
};
