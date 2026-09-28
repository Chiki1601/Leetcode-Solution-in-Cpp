class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int> mpp;
        int cr = 0, mx = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) cr++;
            else{
                mpp[{nums[i], nums[i-1]}]++;
                mpp[{nums[i-1], nums[i]}]++;
            }
        }

        for(auto it : mpp)
            mx = max(mx, it.second);

        return cr + mx;
    }
};
