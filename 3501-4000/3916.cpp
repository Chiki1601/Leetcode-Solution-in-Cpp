class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1)
            return {0};
        int cnt = 0;
        vector<int> ans{};
        for(int i = 0; i < sz-1; ++i)
        {
            cnt = 0;
            for(int j = i+1; j < sz; ++j)
            {
                if(nums[i]%2 == 1 && nums[j]%2 == 0)
                    ++cnt;
                if(nums[i]%2 == 0 && nums[j]%2 == 1)
                    ++cnt;
            }
            ans.push_back(cnt);
        }
        ans.push_back(0);
        return ans;
    }
};
